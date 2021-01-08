#include <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@interface UIView (fconstraints)
-(void)anchorTop:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)top 
         leading:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)leading 
          bottom:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)bottom 
        trailing:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)trailing 
         padding:(UIEdgeInsets)insets 
            size:(CGSize)size ;
            
-(void)anchorCenterX:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)centerX 
             centerY:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)centerY 
                size:(CGSize)size ;
@end
NS_ASSUME_NONNULL_END