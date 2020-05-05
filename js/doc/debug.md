# JS et déboggage

## En pratique

### Sans browser

- `nodejs inspect ./scope.js`

#### Commandes dans le deboggueur (dans le terminal)

- `help`
- `n`
- `list()`
- `list(10)`
- `exec('x')`
- `exec('console.log(x)')`

### Avec browser

#### `chromium-browser` (chrome)

- `nodejs --inspect-brk scope-c.js`

```bash
Debugger listening on ws://127.0.0.1:9229/0087fdab-e9f3-4289-8c9e-0dd441f6d26f
For help see https://nodejs.org/en/docs/inspector
```

- `devtools://devtools/bundled/js_app.html?experiments=true&v8only=true&ws=//127.0.0.1:9229/4deb38a9-e060-4180-a324-2bfb9356a5cf`
- `devtools://devtools/bundled/js_app.html?experiments=true&v8only=true&ws=127.0.0.1:9229/fca2a426-8797-41ca-9689-3f83282f0b4f`

> L'UUID est modifié à chaque lancement du déboggueur

> Copier / coller `ws://127.0.0.1:9229/0087fdab-e9f3-4289-8c9e-0dd441f6d26f` \
> en **remplaçant** les `:` par un `=` \
> ce qui donne `ws=//127.0.0.1:9229/0087fdab-e9f3-4289-8c9e-0dd441f6d26f`

- `chromium-browser`

> Entrer l'URL : `devtools://devtools/bundled/js_app.html?experiments=true&v8only=true&ws=//127.0.0.1:9229/0087fdab-e9f3-4289-8c9e-0dd441f6d26f` \
> `F12` pour entrer dans le mode développeur

## Biblio

- [nodejs.org](https://nodejs.org/api/debugger.html)
- [nodejs.org inspect](https://nodejs.org/en/docs/guides/debugging-getting-started/)
- [chromium](https://developers.google.com/web/tools/chrome-devtools/workspaces/)
- [developers.google](https://developers.google.com/web/tools/chrome-devtools/sources?utm_source=devtools&utm_campaign=2018Q1#edit)
