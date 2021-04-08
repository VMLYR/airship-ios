/* Copyright Airship and Contributors */

#import <Foundation/Foundation.h>
#import "UAAirshipAutomationCoreImport.h"

NS_ASSUME_NONNULL_BEGIN

@interface UAInAppAudienceHistorian : NSObject

/**
* UAInAppAudienceHistorian initializer.
*
* @param channel The channel.
* @param namedUser The named user.
* @return The initialized historian.
*/
+ (instancetype)historianWithChannel:(UAChannel *)channel
                           namedUser:(UANamedUser *)namedUser;

/**
 * Gets tag history newer than the provided date.
 * @param date The date.
 * @return An array of tag history.
 */
- (NSArray<UATagGroupsMutation *> *)tagHistoryNewerThan:(NSDate *)date;

/**
 * Gets attribute history newer than the provided date.
 * @param date The date.
 * @return An array of attribute mutation history.
 */
- (NSArray<UAAttributePendingMutations *> *)attributeHistoryNewerThan:(NSDate *)date;

@end

NS_ASSUME_NONNULL_END
