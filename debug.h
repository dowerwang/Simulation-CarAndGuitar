#pragma once
#ifndef DEBUG_H_
#define DEBUG_H_
#ifdef _DEBUG
#define DEBUG(a) std::cout << a << std::endl;
#else
#define DEBUG(a)
#endif                                              
#endif  
