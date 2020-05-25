#ifndef _MACRO_HPP
#define _MACRO_HPP

#define TRACE_FUNC(X)                                                          \
  std::cout << __func__ << " [" << (X)->_id << "]" << std::endl

#define LOG_FUN std::cout << __func__ << std::endl

#endif
