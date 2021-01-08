#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

@interface GcImagePickerUtils : NSObject
+ (UIImage *)imageFromDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (NSData *)dataFromDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (NSURL *)videoURLFromDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (BOOL)isVideoInDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (BOOL)isImageInDefaults:(NSString *)defaults withKey:(NSString *)key ;
@end