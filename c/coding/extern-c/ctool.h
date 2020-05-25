#ifndef _CTOOL_H
#define _CTOOL_H

enum e { e_0, e_1 };

const char *tell_a();
const char *tell_b();

struct s {
  enum e type;
  const char mes[10];
  const char *(*m_f)(void);
};

#endif
