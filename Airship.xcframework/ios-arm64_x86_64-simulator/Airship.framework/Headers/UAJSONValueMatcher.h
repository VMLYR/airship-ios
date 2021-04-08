/* Copyright Airship and Contributors */

#import <Foundation/Foundation.h>

@class UAJSONPredicate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents the possible error conditions when deserializing matcher from JSON.
 */
typedef NS_ENUM(NSInteger, UAJSONValueMatcherErrorCode) {
    /**
     * Indicates an error with the matcher JSON definition.
     */
   UAJSONValueMatcherErrorCodeInvalidJSON,
};

/**
 * The domain for NSErrors generated by `matcherWithJSON:error:`.
 */
extern NSString * const UAJSONValueMatcherErrorDomain;

/**
 * Defines a JSON value matcher.
 */
@interface UAJSONValueMatcher : NSObject

///---------------------------------------------------------------------------------------
/// @name JSON Value Matcher Properties
///---------------------------------------------------------------------------------------

/**
 * The matcher's JSON payload.
 */
@property(nonatomic, readonly) NSDictionary *payload;

///---------------------------------------------------------------------------------------
/// @name JSON Value Matcher Factories
///---------------------------------------------------------------------------------------

/**
 * Factory method to create a matcher for a number that is
 * at least the specified number.
 *
 * @param number The lower bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtLeast:(NSNumber *)number;

/**
 * Factory method to create a matcher for a number between
 * the lowerNumber and higherNumber.
 *
 * @param lowerNumber The lower bound for the number.
 * @param higherNumber The upper bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtLeast:(NSNumber *)lowerNumber atMost:(NSNumber *)higherNumber;

/**
 * Factory method to create a matcher for a number that is
 * at most the specified number.
 *
 * @param number The upper bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtMost:(NSNumber *)number;

/**
 * Factory method to create a matcher for an exact number.
 *
 * @param number The expected number value.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberEquals:(NSNumber *)number;

/**
 * Factory method to create a matcher for an exact boolean.
 *
 * @param boolean The expected boolean value.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereBooleanEquals:(BOOL)boolean;

/**
 * Factory method to create a matcher for an exact string.
 *
 * @param string The expected string value.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereStringEquals:(NSString *)string;

/**
 * Factory method to create a matcher for the presence of a value.
 *
 * @param present `YES` if the value must be present, otherwise `NO`.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereValueIsPresent:(BOOL)present;

/**
 * Factory method to create a matcher for a version constraint.
 *
 * @param versionConstraint The version constraint to be matched against.
 * @return A value matcher.
 */
+ (nullable instancetype)matcherWithVersionConstraint:(NSString *)versionConstraint;

/**
 * Factory method to create a matcher for an array value.
 *
 * @param predicate A predicate to be used to evaluate each value in the array for a match.
 * @return A value matcher.
 */
+ (nullable instancetype)matcherWithArrayContainsPredicate:(UAJSONPredicate *)predicate;

/**
 * Factory method to create a matcher for a value in an array.
 *
 * @param predicate A predicate to be used to evaluate the value at the index.
 * @param index The array index.
 * @return A value matcher.
 */
+ (nullable instancetype)matcherWithArrayContainsPredicate:(UAJSONPredicate *)predicate atIndex:(NSUInteger)index;

/**
 * Factory method to create a matcher from a JSON payload.
 *
 * @param json The JSON payload.
 * @param error An NSError pointer for storing errors, if applicable.
 * @return A value matcher, or `nil` if the JSON is invalid.
 */
+ (nullable instancetype)matcherWithJSON:(id)json error:(NSError * _Nullable *)error;

///---------------------------------------------------------------------------------------
/// @name JSON Value Matcher Evaluation
///---------------------------------------------------------------------------------------

/**
 * Evaluates the object with the matcher.
 *
 * @param object The object to evaluate.
 * @return `YES` if the matcher matches the object, otherwise `NO`.
 */
- (BOOL)evaluateObject:(nullable id)object;

/**
 * Evaluates the object with the matcher.
 *
 * @param object The object to evaluate.
 * @param ignoreCase {@code YES} to ignore case when checking String values, {@code NO} to check case.
 * Strings contained in arrays and dictionaries also follow this rule.
 * @return `YES` if the matcher matches the object, otherwise `NO`.
 */
- (BOOL)evaluateObject:(nullable id)object ignoreCase:(BOOL)ignoreCase;

@end

NS_ASSUME_NONNULL_END
