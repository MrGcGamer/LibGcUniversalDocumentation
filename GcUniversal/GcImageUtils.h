// By: @MrGcGamer
#import <UIKit/UIKit.h>

@interface UIImage (imageUtils)
+ (UIImage *)stockImgForBundleID:(NSString *)arg1 ;
+ (UIImage *)thumbnailForImage:(UIImage *)image withMaxSize:(CGFloat)maxSize scale:(CGFloat)scale ;
- (UIColor *)averageColor;
- (NSArray <UIColor *> *)dominantColors;
@end