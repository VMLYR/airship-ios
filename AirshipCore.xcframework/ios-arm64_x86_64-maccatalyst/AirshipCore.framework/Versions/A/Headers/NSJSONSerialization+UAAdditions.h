/* Copyright Airship and Contributors */

#import <Foundation/Foundation.h>

/**
 * Represents the possible error conditions when serializing JSON objects.
 */
typedef NS_ENUM(NSInteger, UAJSONSerializationErrorCode) {
    /**
     * Indicates an error in serializing an invalid object.
     */
    UAJSONSerializationErrorCodeInvalidObject
};

NS_ASSUME_NONNULL_BEGIN

/**
 * The domain for NSErrors generated by the NSJSONSerialization+UAAdditions methods.
 */
extern NSString * const UAJSONSerializationErrorDomain;


/**
 * The NSJSONSerialization convenience methods.
 */
@interface NSJSONSerialization (UAAdditions)

///---------------------------------------------------------------------------------------
/// @name JSON Serialization Additions Core Methods
///---------------------------------------------------------------------------------------

/**
 * Converts a Foundation object to a JSON formatted NSString
 * @param jsonObject Foundation object to convert 
 * @return NSString formatted as JSON, or `nil` if an error occurs
 * @note Writing JSON strings with this method defaults to no NSJSONWritingOptions, and does not accept fragments.
 */
+ (nullable NSString *)stringWithObject:(id)jsonObject;

/**
 * Converts a Foundation object to a JSON formatted NSString
 * @param jsonObject Foundation object to convert
 * @param error An NSError pointer for storing errors, if applicable.
 * @return NSString formatted as JSON, or `nil` if an error occurs
 * @note Writing JSON strings with this method defaults to no NSJSONWritingOptions, and does not accept fragments.
 */
+ (nullable NSString *)stringWithObject:(id)jsonObject error:(NSError **)error;

/**
 * Converts a Foundation object to a JSON formatted NSString
 * @param jsonObject Foundation object to convert
 * @param acceptingFragments `YES` if objects representing JSON value fragments are acceptable, `NO` otherwise.
 * @return NSString formatted as JSON, or `nil` if an error occurs.
 * @note Writing JSON strings with this method defaults to no NSJSONWritingOptions.
 */
+ (nullable NSString *)stringWithObject:(id)jsonObject acceptingFragments:(BOOL)acceptingFragments;

/**
 * Converts a Foundation object to a JSON formatted NSString
 * @param jsonObject Foundation object to convert
 * @param acceptingFragments `YES` if objects representing JSON value fragments are acceptable, `NO` otherwise.
 * @param error An NSError pointer for storing errors, if applicable.
 * @return NSString formatted as JSON, or `nil` if an error occurs.
 * @note Writing JSON strings with this method defaults to no NSJSONWritingOptions.
 */
+ (nullable NSString *)stringWithObject:(id)jsonObject acceptingFragments:(BOOL)acceptingFragments error:(NSError **)error;

/**
 * Converts a Foundation object to a JSON formatted NSString
 * @param jsonObject Foundation object to convert
 * @param opt NSJSONWritingOptions options
 * @return NSString formatted as JSON, or `nil` if an error occurs
 */
+ (nullable NSString *)stringWithObject:(id)jsonObject options:(NSJSONWritingOptions)opt;

/**
 * Converts a Foundation object to a JSON formatted NSString
 * @param jsonObject Foundation object to convert
 * @param opt NSJSONWritingOptions options
 * @param error An NSError pointer for storing errors, if applicable.
 * @return NSString formatted as JSON, or `nil` if an error occurs
 */
+ (nullable NSString *)stringWithObject:(id)jsonObject options:(NSJSONWritingOptions)opt error:(NSError **)error;


/**
 * Create a Foundation object from JSON string
 * @param jsonString the JSON NSString to convert
 * @return A Foundation object, or `nil` if an error occurs.
 * @note Creating objects with this method defaults to NSJSONReadingMutableContainers options.
 */
+ (nullable id)objectWithString:(NSString *)jsonString;

/**
 * Create a Foundation object from JSON string
 * @param jsonString the JSON NSString to convert
 * @param opt NSJSONReadingOptions
 * @return A Foundation object, or `nil` if an error occurs.
 */
+ (nullable id)objectWithString:(NSString *)jsonString options:(NSJSONReadingOptions)opt;

/**
 * Create a Foundation object from JSON string
 * @param jsonString the JSON NSString to convert
 * @param opt NSJSONReadingOptions
 * @param error An NSError pointer for storing errors, if applicable.
 * @return A Foundation object, or `nil` if an error occurs.
 */
+ (nullable id)objectWithString:(NSString *)jsonString options:(NSJSONReadingOptions)opt error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END