# Outils d'analyse de code

## Static Application Security Testing

_Ce sont les outils SAST_

| Outils    | Information                                      | analyse  | Remarques |
|-----------|--------------------------------------------------|----------|-----------|
| semgrep   | utilise des règles définies dans un fichier YAML | statique | gratuit   |
| cppcheck  | spécialisé pour le C++                           | statique | gratuit   |
| SonarQube | score, ratio, graphique, très riche              | statique | payant    |

## Runtime

| Outils   | Information               | analyse   | Remarques            |
|----------|---------------------------|-----------|----------------------|
| asan     | pertinent                 | dynamique | gratuit              |
| valgrind | détection fuites mémoires | dynamique | execution très lente |

## Couverture de code

- gcov
- lcov
