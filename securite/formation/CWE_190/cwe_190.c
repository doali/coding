/*
** Comments : CWE 190 - Integer Overflow or Wraparound applied on the 
**	vulnerabilities found on OpenSSH 3.3 (CVE-2002-0639).
**	cwe: http://cwe.mitre.org/data/definitions/190.html
**	cve: http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2002-0639
**
** Targeted software: OpenSSH 3.3
**	file(s): ssh/auth2-chall.c:241
**	function(s): input_userauth_info_response
*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char** responses;
    uint32_t i;
    // number of response (in a packet) belong to [0; (2**32) - 1]
    uint32_t n_resp;
    size_t len;  // real size of the allocated buffer

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <nb_response>\n", argv[0]);
        exit(1);
    }

    // do not take care of usage of atoi()
    n_resp = atoi(argv[1]);
    printf("You ask for %u responses\n", n_resp);

    if (n_resp > 0) {
        // Integer overflow here if n_resp * sizeof(char*) > 2^32 - 1
        len = n_resp * sizeof(char*);
        printf(
            "So I will allocate a buffer of %u byte (this value could be "
            "aligned)\n",
            len);
        responses = (char**)malloc(len);
        assert(responses != NULL);

        for (i = 0; i < n_resp; ++i) {
            // Buffer Overflow si Integer Overflow
            responses[i] = "toto";
        }
    }

    return (0);
}