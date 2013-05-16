

#import "TTYinaBOXDelegate.h"
#import "ShellBundleLoaderProtocol.h"

@implementation  TTYinaBOXDelegate

- (void)applicationWillFinishLaunching:(NSNotification *)aNotification {
	
	// Get the plugin
	NSArray* plugins	= [NSBundle pathsForResourcesOfType:@"plugin" inDirectory:
							   NSBundle.mainBundle.builtInPlugInsPath];
	NSLog(@"Plugins: %@", plugins);
	NSBundle *bndl 	= [NSBundle bundleWithPath:[plugins lastObject]];
	NSError *err 		= nil;
	BOOL ok = [bndl preflightAndReturnError:&err];
	if (err) NSLog(@"Error: %@", err);
	else		NSLog(@"Success preflighting: %@ ... %@", ok ? @"OK" : @"NOT OK", 
						[bndl load] ? @"LOADED" : @"PROBLEMO!");
	
	// instantiate the principal class and call the method
	Class pClass = bndl.principalClass;	
	id bObj 			= [[pClass alloc]init];
	NSLog(@"Principal:%@    Obj:%@", NSStringFromClass(pClass), bObj);

	NSInteger zInt = [bObj addOneInteger:100 toAnother:23];
	NSLog(@"BaseAppAppDelegate zInt = %ld",zInt);	
	[bObj setValue:@YES forKey:@"serverRunning"];
	
} // end applicationWillFinishLaunching



@end