// By: @MrGcGamer
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, ColorComponent) {
   kColorRed,
   kColorGreen,
   kColorBlue,
   kColorHue,
   kColorSaturation,
   kColorBrightness,
   kColorAlpha
};

@interface UIColor (colorUtils)
+ (UIColor *)closestColorFromArray:(NSArray *)colors toColor:(UIColor *)color ;
- (CGFloat)getColorComponent:(ColorComponent)component ;
- (CGFloat)rgbValue;
- (BOOL)isGrayscale;
- (BOOL)isNearGrayscale;
- (BOOL)isDarkColor;
- (BOOL)isLightColor;
@end