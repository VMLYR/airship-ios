/* Copyright Airship and Contributors */

#import <Foundation/Foundation.h>
#import "UALocationCoreImport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Location module loader.
 * @note For internal use only. :nodoc:
 */
@interface UALocationModuleLoader : NSObject<UAModuleLoader, UALocationModuleLoaderFactory, UALocationProviderLoader>

@end


NS_ASSUME_NONNULL_END
