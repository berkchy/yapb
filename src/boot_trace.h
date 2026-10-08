/*
========================
boot_trace.h

The xash3d boot goes silent inside Game::Postload(), so logcat has to say
which step it stopped on. Printed straight to logcat: the engine logger is not
up yet this early and the Android runtime discards stderr.

Keep the helper in a header rather than a static function so the whole boot
path can call it from several translation units.
========================
*/
#ifndef BOOT_TRACE_H
#define BOOT_TRACE_H

#include <stdio.h>

#if defined(__ANDROID__)
#include <android/log.h>
#endif

static inline void boot_trace(const char *stage) {
#if defined(__ANDROID__)
  __android_log_write(ANDROID_LOG_INFO, "yapb", stage);
#else
  fprintf(stderr, "[yapb] boot: %s\n", stage);
#endif
}

#endif // BOOT_TRACE_H