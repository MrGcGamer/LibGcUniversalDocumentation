// By: @MrGcGamer
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

@interface GcColorPickerUtils : NSObject
+ (NSString *)hexStringFromColor:(UIColor *)color ;
+ (UIColor *)colorWithHex:(NSString *)hexStr ;
+ (UIColor *)colorFromDefaults:(NSString *)defaults withKey:(NSString *)key ;
+ (UIColor *)colorFromDefaults:(NSString *)defaults withKey:(NSString *)key fallback:(NSString *)fallback ;
@end