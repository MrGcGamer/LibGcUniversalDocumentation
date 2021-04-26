#include <UIKit/UIKit.h>

@interface UIImage (imageUtils)
+ (UIImage *)stockImgForBundleID:(NSString *)arg1 ;
- (UIColor *)averageColor;
- (NSArray <UIColor *> *)dominantColors;
@end