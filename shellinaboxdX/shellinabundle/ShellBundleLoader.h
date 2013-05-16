//  PluginPrincipalClass.h

#import "ShellBundleLoaderProtocol.h"

// shellinaboxd.c -- A custom web server that makes command line applications available as AJAX web applications.  http://shellinabox.com


#define _GNU_SOURCE
#include "config.h"

#include <fcntl.h>
#include <getopt.h>
#include <limits.h>
#include <locale.h>
#include <poll.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef HAVE_SYS_PRCTL_H
#include <sys/prctl.h>
#endif

#include "libhttp/http.h"
#include "logging/logging.h"
#include "shellinabox/externalfile.h"
#include "shellinabox/launcher.h"
#include "shellinabox/privileges.h"
#include "shellinabox/service.h"
#include "shellinabox/session.h"
#include "shellinabox/usercss.h"

#ifdef HAVE_UNUSED
#defined ATTR_UNUSED __attribute__((unused))
#defined UNUSED(x)   do { } while (0)
#else
#define ATTR_UNUSED
#define UNUSED(x)    do { (void)(x); } while (0)
#endif

// Embedded resources
#include "shellinabox/beep.h"
#include "shellinabox/cgi_root.h"
#include "shellinabox/enabled.h"
#include "shellinabox/favicon.h"
#include "shellinabox/keyboard.h"
#include "shellinabox/keyboard-layout.h"
#include "shellinabox/print-styles.h"
#include "shellinabox/root_page.h"
#include "shellinabox/shell_in_a_box.h"
#include "shellinabox/styles.h"
#include "shellinabox/vt100.h"

#define PORTNUM           4200
#define MAX_RESPONSE      2048

@interface ShellBundleLoader : NSObject <ShellBundleLoaderProtocol> {}

@property (nonatomic) BOOL serverRunning;
+ (ShellBundleLoader *)sharedLoader;
- (NSInteger)addOneInteger:(NSInteger)pInt1 toAnother:(NSInteger)pInt2;

@end
