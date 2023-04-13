// By: @MrGcGamer
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@interface UIView (fconstraints)
-(void)anchorTop:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)top
         leading:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)leading
          bottom:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)bottom
        trailing:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)trailing
         padding:(UIEdgeInsets)insets
            size:(CGSize)size ;

-(void)anchorTop:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)top
         leading:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)leading
          bottom:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)bottom
        trailing:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)trailing
         padding:(UIEdgeInsets)insets ;

-(void)anchorTop:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)top
         leading:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)leading
          bottom:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)bottom
        trailing:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)trailing
            size:(CGSize)size ;

-(void)anchorTop:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)top
         leading:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)leading
          bottom:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)bottom
        trailing:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)trailing ;

-(void)anchorCenterX:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)centerX
             centerY:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)centerY
                size:(CGSize)size ;

-(void)anchorCenterX:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)centerX
             centerY:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)centerY ;

-(void)anchorEqualsToView:(UIView *)view padding:(UIEdgeInsets)insets ;
-(void)anchorEqualsToView:(UIView *)view ;
@end

#if __cplusplus
extern "C" {
#endif

void logToFile(NSString *path, NSString *log);

#if __cplusplus
}
#endif

NS_ASSUME_NONNULL_END