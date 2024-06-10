// By: @MrGcGamer
#import <UIKit/UIKit.h>

FOUNDATION_EXPORT BOOL isHEICSupported(void);
#if __IPHONE_OS_VERSION_MAX_ALLOWED < 170000
FOUNDATION_EXPORT NSData *UIImageHEICRepresentation(UIImage *image, CGFloat compressionQuality);
#endif

@interface UIImage (imageUtils)
+ (UIImage *)stockImgForBundleID:(NSString *)arg1 ;
+ (UIImage *)thumbnailForImage:(UIImage *)image withMaxSize:(CGFloat)maxSize scale:(CGFloat)scale ;
- (UIColor *)averageColor;
- (NSArray <UIColor *> *)dominantColors;
@end
