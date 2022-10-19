#!/usr/bin/env bash

# --------------------------------------------------------------------------------
# Protobuf withing python
# https://www.freecodecamp.org/news/googles-protocol-buffers-in-python/
# --------------------------------------------------------------------------------

readonly DEP_PROTO=protobuf
#readonly PROTO_FILE=todolist.proto
readonly PROTO_FILE=todolist.proto3

# Important (while using protoc)
# - <file>.proto3 creates <file> directory and proto3_pb2.py file inside it
# - <file>.proto creates <file>_pb2.py
# --------------------------------------------------------------------------------

install() {
	local ret_proto_present=-1
	local version_proto=$(pip freeze -q | grep -i ${DEP_PROTO} 2>/dev/null)

	ret_proto_present=$?
	if [ ${ret_proto_present} -ne 0 ]; then
		pip install ${DEP_PROTO}
	else
		echo "${version_proto}...ok"
	fi
}
		
generate() {
	protoc -I=. --python_out=. ./${PROTO_FILE}
	[ $? -eq 0 ] && echo "protoc ${PROTO_FILE}...ok" || echo "protoc...ko"
}

export_module() {
    [ "${PROTO_FILE##*.}" == "proto3" ] && touch ${PROTO_FILE%.proto3}/__init__.py
}

main() {
	install
	generate
	export_module
}

# --------------------------------------------------------------------------------
main
