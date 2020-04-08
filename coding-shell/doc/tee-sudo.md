# Tee and sudo

_Using tee instead of cat_ (Here TAG)

_[...] I wanted to share this anyway: I had the need to create a config file in a directory that required root rights._

> The following does not work for that case

```bash
$ sudo cat <<EOF >/etc/somedir/foo.conf
# my config file
foo=bar
EOF
```

> because the redirection is handled outside of the sudo context. \
> I ended up using this instead

```bash
$ sudo tee <<EOF /etc/somedir/foo.conf >/dev/null
# my config file
foo=bar
EOF
```

## Biblio
- [stack over flow](https://stackoverflow.com/questions/2500436/how-does-cat-eof-work-in-bash)