
#ifndef __SHARED_EXPORT_HPP__
#define __SHARED_EXPORT_HPP__

#ifdef WIN32
#    ifdef QtQmlTricks_SHARED
#        define QtQmlTricks_API_ __declspec(dllexport)
#    elif QtQmlTricks_STATIC
#        define QtQmlTricks_API_
#    else
#        define QtQmlTricks_API_ __declspec(dllimport)
#    endif
#else
#    define QtQmlTricks_API_
#endif

#endif
