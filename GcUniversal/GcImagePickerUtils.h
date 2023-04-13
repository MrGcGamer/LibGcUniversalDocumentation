// By: @MrGcGamer
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

typedef NS_CLOSED_ENUM(NSUInteger, ImagegSizingMode) {
	kSizingModeMin,
	kSizingModeMax
};

typedef struct {
	ImagegSizingMode sizingMode;
	CGFloat size;
	CGFloat scale;
} ImageSizingConfig;

@interface GcImagePickerUtils : NSObject
+ (UIImage *)imageFromDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (UIImage *)imageFromDefaults:(NSString *)defaults withKey:(NSString *)key error:(NSError **)error ;
+ (UIImage *)thumbnailFromDefaults:(NSString *)defaults withKey:(NSString *)key forSizingMode:(ImagegSizingMode)sizingMode ;
+ (UIImage *)thumbnailFromDefaults:(NSString *)defaults withKey:(NSString *)key forConfig:(ImageSizingConfig)sizingConfig ;
+ (UIImage *)thumbnailFromDefaults:(NSString *)defaults withKey:(NSString *)key maxSize:(CGFloat)maxSize scale:(CGFloat)scale ;
+ (UIImage *)thumbnailFromDefaults:(NSString *)defaults withKey:(NSString *)key minSize:(CGFloat)minSize scale:(CGFloat)scale ;
+ (UIImage *)thumbnailForURL:(NSURL *)url maxSize:(CGFloat)maxSize scale:(CGFloat)scale ;
+ (UIImage *)thumbnailForURL:(NSURL *)url minSize:(CGFloat)minSize scale:(CGFloat)scale ;
+ (NSData *)dataFromDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (NSData *)dataFromDefaults:(NSString *)defaults withKey:(NSString *)key error:(NSError **)error ;
+ (NSURL *)videoURLFromDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (BOOL)isVideoInDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (BOOL)isImageInDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (BOOL)setImage:(UIImage *)image forDefaults:(NSString *)defaults withKey:(NSString *)key png:(BOOL)png ;
@end