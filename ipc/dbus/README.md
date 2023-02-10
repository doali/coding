# D-Bus 

## Description

- acronyme de _Desktop Bus_
- protocole de communication inter-processus
- bus logiciel
- implémenté et developpé à l'origine par RedHat via le projet freedesktop.org
- existence de différents bindings (réécriture de la bibliothèque dans un autre langage que le langage initial)

## Exploitation

Exemple d'utilisation de D-Bus : Qt4, KDE4, GNOME, Enlightenment, Android

## Principe

**daemon**
- Présence d'un processus serveur qui traite des demandes clientes
- vérifie les autorisations avant de transmettre les messages
- lance le processus si un message lui est destiné ou associé
- retourne tous les services disponibles sur le bus (introspection des services)
- retourne la signature des méthodes (introspection des méthodes)
- un service peut porter un descripteur de fichier (ouvert) à un autre service

**bus**
- une unique instance du bus système ou encore `system channel`
- plusieurs instances possibles de bus session ou encore `session channel`
  - la session est celle de l'utilisateur d'un point de vue linux

**client**
- un processus (application, programme, ...) communique avec le démon
- s'enregistre auprès d'une instance d'un bus ou encore `channel` et y expose des services
- publie des messages en diffusion `signals` (l'expéditeur à l'initiative du message n'attent pas de réponse)
- réalise des appels de méthodes `methods` (l'expéditeur ou appelant attent une réponse)

Les messages sont sérialisés sous forme de flux d'octets (pas de format JSON, XML ou autre...)

## Préparation de l'environnement

## Code

**freedesktop**

- [repository](https://cgit.freedesktop.org/dbus)

**Tuto**
> [matthew](https://www.matthew.ath.cx/misc/dbus)

## Biblio

**D-Bus**

- [wikipedia](https://fr.wikipedia.org/wiki/D-Bus)
- [linuxembedded](https://www.linuxembedded.fr/2015/07/comprendre-dbus)
- [josserand](https://bootlin.com/pub/conferences/2016/meetup/dbus/josserand-dbus-meetup.pdf)

> freedesktop
- [freedesktop](https://www.freedesktop.org/wiki/Software/dbus/)
- [freedesktop introduction to D-Bus](https://www.freedesktop.org/wiki/IntroductionToDBus/)
- [freedesktop archive](https://www.freedesktop.org/wiki/IntroductionToDBus/)
- [freedesktop pseudo-code example](https://dbus.freedesktop.org/doc/dbus-tutorial.html)

> python

- [freedesktop python example](https://dbus.freedesktop.org/doc/dbus-python/tutorial.html)
- [python D-Bus implementations](https://wiki.python.org/moin/DbusExamples)
- [python pydbus](https://github.com/LEW21/pydbus)
- [python dasbus](https://github.com/rhinstaller/dasbus)

> gnome
- [gnome gtk](https://docs.gtk.org/gio/)
- [IBM](https://archive.wikiwix.com/cache/index2.php?url=http%3A%2F%2Fwww-128.ibm.com%2Fdeveloperworks%2Flinux%2Flibrary%2Fl-dbus.html#federation=archive.wikiwix.com&tab=url)

> Qt

- [Qt D-Bus](https://doc.qt.io/qt-5/qtdbus-index.html)
- [Qt examples](https://doc.qt.io/qt-6/examples-dbus.html)

**Docker**
- [Dockerfile ARG](https://docs.docker.com/engine/reference/builder/)
- [D-Bus dbus-monitor](https://unix.stackexchange.com/questions/646934/d-bus-on-ubuntu-inside-a-docker-container)
