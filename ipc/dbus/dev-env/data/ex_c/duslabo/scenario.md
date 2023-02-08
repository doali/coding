# Scenario

## Using command line `dbus-send`

Ensure 
- that process `server` exists (or compile it with `make`)
- is not already running (otherwise `killall server`)

In a terminal run the server `./server` \
And in another terminal

`dbus-send --session --dest=test.foo.bar --print-reply / test.foo.Roll.Method`

> This scenario is rendered in the following script

```bash
scenario_2() {
    ./server &
    local -r pid_server=$!
    echo "[${pid_server}] server running"
    sleep 2
    dbus-send --session --dest=test.foo.bar --print-reply --reply-timeout=500 / test.foo.Roll.Method
    sleep 1
    kill -s term ${pid_server}
    echo "[${pid_server}] server killed"
}

# WARNING !!! process server uses 98% of CPU !!!
compilation() {
    for exe in server client; do [ -f ${exe} ] && rm ${exe}; done
    make
}
```

> WARNING !!! process server uses 98% of CPU !!!