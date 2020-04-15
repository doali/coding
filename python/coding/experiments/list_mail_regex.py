#!/usr/bin/env python3

import re

def main():
    emails_rx = ["xav@lol.com", "yo@lol.com"]

    nb_rx_emails = len(emails_rx)
    orth = "s" if (nb_rx_emails > 1) else ""

    if nb_rx_emails > 0:
        # msg = "%d email%s from :%s" % (nb_rx_emails, orth, emails_rx) # str style standard
        # msg = "{} email{} from :{}".format(nb_rx_emails, orth, emails_rx) # str.format style
        msg = f"{nb_rx_emails} email{orth} from :{emails_rx}"  # f string
        print(msg)

    for email in emails_rx:
        res = re.search("^yo@.*", email)
        if res:
            print(f"{res.group()} :-)")


if __name__ == "__main__":
    main()
