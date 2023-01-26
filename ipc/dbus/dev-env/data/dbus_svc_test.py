#!/usr/bin/env python

# ------------------------------------------------------------------------------
# Exemple repris
# https://unix.stackexchange.com/questions/646934/d-bus-on-ubuntu-inside-a-docker-container
# ------------------------------------------------------------------------------

from gi.repository import GObject as gobject
import dbus
import dbus.service
import dbus.mainloop.glib
import sys

service_name = "com.testservice"
object_path = "/testservice"
interface_name = service_name

class SomeObject(dbus.service.Object):

    def __init__(self, bus, object_path):
        dbus.service.Object.__init__(self, bus, object_path)
    
    @dbus.service.method(service_name, in_signature='', out_signature='')
    def Exit(self):
        mainloop.quit()


if __name__ == '__main__':
    dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)

    session_bus = dbus.SessionBus()
    name = dbus.service.BusName(service_name, session_bus)
    object = SomeObject(session_bus, object_path)

    mainloop = gobject.MainLoop()
    mainloop.run()

