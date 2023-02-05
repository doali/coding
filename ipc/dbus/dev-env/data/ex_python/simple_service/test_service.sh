#!/usr/bin/env bash

dbus-send --print-reply --session --dest=com.testservice /testservice com.testservice.Exit
