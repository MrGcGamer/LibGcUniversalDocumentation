# LibGcUniversal
LibGcUniversal is a universal library for tweak development I made because I think it's annoying to add a new library for every little thing.

## Contents of LibGcUniversal
 - [GcColorPickerCell](https://github.com/MrGcGamer/LibGcUniversalDocumentation#implementation-of-a-color-picker)
 - [GcImagePickerCell](https://github.com/MrGcGamer/LibGcUniversalDocumentation#implementation-of-an-image-picker)
 - [GcTwitterCell](https://github.com/MrGcGamer/LibGcUniversalDocumentation#implementation-of-a-twitter-cell)
 - [GcDuoTwitterCell](https://github.com/MrGcGamer/LibGcUniversalDocumentation#implementation-of-a-duo-twitter-cell)
 - [Little helper functions for NSLayoutConstraints](https://github.com/MrGcGamer/LibGcUniversalDocumentation#using-the-helper-functions-for-nslayoutconstraints)
 - [Color utils](https://github.com/MrGcGamer/LibGcUniversalDocumentation#using-the-color-utils)
 - [Image utils](https://github.com/MrGcGamer/LibGcUniversalDocumentation#using-the-image-utils)

# Usage

## Installation in Theos

### Automatic installation

Run the `install.sh` script in this repository to automatically copy the necessary files.

### Manual installation

1. Download this repository
2. Put the `.dylib` into your `theos/lib` folder
3. Put the `GcUniversal` folder into your `theos/include` folder
4. Done!

## Project configuration
1. Add `TWEAKNAME_LIBRARIES = gcuniversal` to your makefiles (only to your tweak makefile if you only use the helper functions)
2. Add `com.mrgcgamer.libgcuniversal` to the `Depends` in your `control` file
3. Done!

## Implementation of a color picker
PreferenceBundle plist (Root.plist e.g.)
```xml
    <dict>
        <key>cell</key>
        <string>PSLinkCell</string>
        <key>cellClass</key>
        <string>GcColorPickerCell</string>
        <key>label</key>
        <string>Your Color Label</string>
        <key>defaults</key>
        <string>com.your.identifier</string>
        <key>key</key>
        <string>YourColor</string>
        <key>supportsAlpha</key>
        <true/>
        <key>safeOnDismiss</key>
        <true/>
        <key>fallback</key>
        <string>ffffffff</string>
    </dict>
```
### supportsAlpha
The `supportsAlpha` property is optional and will default to `true` if nothing else has been specified.

### safeOnDismiss
The `safeOnDismiss` property is optional and will default to `true` if nothing else has been specified.
When `safeOnDismiss` is turned off, the user will have to press the `X` Button in the top right (or left on RTL langues, I don't know) in order for the color to be saved, when this option is on, the color will be safed even if the colorpicker was dismissed via the swipe down gesture.

### fallback
The `fallback` property is optional and will default to a clear color if the fallback color hasn’t been set.

You may use any color hex code which condones to one of the following color hex code notations:
 - `rgb`
 - `rgba`
 - `rrggbb`
 - `rrggbbaa`
The `a` / `aa` (alpha) value has also to be written an in hex and __NOT__ as `:1.0`.
I recommend using `rrggbbaa`.

Once this is implemented you can then get the chosen color from within your tweak. So an example of how to retrieve the color could look something like this:

```objc
#import "GcUniversal/GcColorPickerUtils.h"

%hook HOOKHERE
-(void)someMethod {
    %orig;

    UIColor *color = [GcColorPickerUtils colorFromDefaults:@"DEFAULTS" withKey:@"KEY"];
}
%end
```

You may also use:
```objc
[GcColorPickerUtils colorFromDefaults:@"DEFAULTS" withKey:@"KEY" fallback:@"ffffffff"]
```
Valid fallback values have to condone one of the notations mentioned above.

## Implementation of an image picker
PreferenceBundle plist (Root.plist e.g.)
```xml
    <dict>
        <key>cell</key>
        <string>PSLinkCell</string>
        <key>cellClass</key>
        <string>GcImagePickerCell</string>
        <key>label</key>
        <string>Your Image Labe</string>
        <key>defaults</key>
        <string>com.your.identifier</string>
        <key>key</key>
        <string>YourImage</string>
        <key>usesPhotos</key>
        <true/>
        <key>usesVideos</key>
        <false/>
        <key>videoQuality</key>
        <integer>1</integer>
    </dict>
```

`usesPhotos` and `usesVideos` are optionals with default values of `true` and `false`.
`videoQuality` is also optional, which can be set, to set the preferred quality of the video.
The default value of `videoQuality` is `1`.
Possible `videoQuality` values are as follows:
`0` = high quality
`1` = medium quality
`2` = low quality

Once this is implemented you can then get the chosen image from within your tweak. So an example of how to retrieve the image could look something like this:

```objc
#import "GcUniversal/GcImagePickerUtils.h"

%hook SOMECLASS
-(void)someMethod {
    %orig;

    UIImage *img = [GcImagePickerUtils imageFromDefaults:@"DEFAULTS" withKey:@"KEY"];
}
%end
```

If you want to get the images data instead of the image you can use:
```objc
NSData *data = [GcImagePickerUtils dataFromDefaults:@"DEFAULTS" withKey:@"KEY"];
```

If you decided to let the user pick a video, you can retrieve an `NSURL` leading to it something like this:
```objc
#import "GcUniversal/GcImagePickerUtils.h"

%hook SOMECLASS
-(void)someMethod {
    %orig;

    NSURL *videoURL = [GcImagePickerUtils videoURLFromDefaults:@"DEFAULTS" withKey:@"KEY"];

    if (videoURL) { // this check is to prevent a chrash in case the user didn't select any media
        // do something with the videoURL
    }
}
%end
```

In case you give the user the ability to choose a video or an image, you can easily check which one they went for, by doing something like this:
```objc
#import "GcUniversal/GcImagePickerUtils.h"

%hook SOMECLASS
-(void)someMethod {
    %orig;

    BOOL isVideo = [GcImagePickerUtils isVideoInDefaults:@"DEFAULTS" withKey:@"KEY"];

    if (isVideo) {
        // do video stuff
    } else {
        // do photo stuff
    }
}
```
It is also possible to check if the user selected an image like this:
```objc
BOOL isPhoto = [GcImagePickerUtils isImageInDefaults:@"DEFAULTS" withKey:@"KEY"];
```
If you prefer that (though it doesn't really make any difference which method you use).

## Implementation of a Twitter cell
PreferenceBundle plist (Root.plist e.g.)
```xml
    <dict>
        <key>cell</key>
        <string>PSButtonCell</string>
        <key>cellClass</key>
        <string>GcTwitterCell</string>
        <key>accountLabel</key>
        <string>LabelForTheAccount</string>
        <key>account</key>
        <string>TwitterTagOfAccount</string>
        <key>URL</key>
        <string>URLToAnotherFancyImage</string>
    </dict>
```
`URL` is an optional value, which can be set, to specify an URL to the images for the account somewhere online.

If don't want to use the URLs, you will also need to include the profile picture of the account in the `Resources` folder of your preferences.
It is recommended to use a picture with a resolution of `400x400`.
The picture will have to have the same name as the Twitter tag of the provided account and be stored as a `.png` file.

## Implementation of a duo Twitter cell
PreferenceBundle plist (Root.plist e.g.)

```xml
    <dict>
        <key>cellClass</key>
        <string>GcDuoTwitterCell</string>
        <key>firstLabel</key>
        <string>LabelForTheFirstAccount</string>
        <key>firstAccount</key>
        <string>TwitterTagOfFirstAccount</string>
        <key>firstURL</key>
        <string>URLToSomeFancyImage</string>
        <key>secondLabel</key>
        <string>LabelForTheSecondAccount</string>
        <key>secondAccount</key>
        <string>TwitterTagOfSecondAccount</string>
        <key>secondURL</key>
        <string>URLToAnotherFancyImage</string>
    </dict>
```
`firstURL` and `secondURL` are optional values, which can be set, to specify an URL to the images for each account somewhere online.
If you use the URLs, make sure they link to the images directly. It is also possible to have only one image loaded using the URL and the other one using local files.

If don't want to use the URLs, you will also need to include the profile pictures of the two accounts in the `Resources` folder of your preferences.
It is recommended to use pictures of a resolution of `400x400`.
The pictures will have to have the same name as the Twitter tag of the corresponding account and be stored as `.png` files.

## Using the helper functions for NSLayoutConstraints
First of all, you will need to import HelperFunction.h as follows:
```objc
#import "GcUniversal/HelperFunctions.h"
```
The `HelperFunctions.h` file includes this interface:
```objc
@interface UIView (extension)
-(void)anchorTop:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)top
         leading:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)leading
          bottom:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)bottom
        trailing:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)trailing
         padding:(UIEdgeInsets)insets
            size:(CGSize)size ;

-(void)anchorCenterX:(nullable NSLayoutAnchor <NSLayoutXAxisAnchor *> *)centerX
             centerY:(nullable NSLayoutAnchor <NSLayoutYAxisAnchor *> *)centerY
                size:(CGSize)size ;

-(void)anchorEqualsToView:(UIView *)view padding:(UIEdgeInsets)insets ;
@end
```
Therefor you can use the HelperFunctions like this:
```objc
UIView *view = [UIView new];
[someOtherView addSubview:view];

[view anchorTop:someOtherView.topAnchor leading:someOtherView.leadingAnchor bottom:nil trailing:nil padding:UIEdgeInsetsMake(32,15,0,0) size:CGSizeMake(64,64)];
```
Now, this would constraint the `topAnchor` of `view` to the `topAnchor` of `someOtherView` with padding of `32`,
also, this would constraint the `leadingAnchor` of `view` to the `leadingAnchor` of `someOtherView` with padding of `15`,
furthermore, this would constraint the `widthAnchor` and `heightAnchor` of `view` to `64` each.

If you are looking for a better explanation of this function, I recommend watching [this](https://www.youtube.com/watch?v=iqpAP7s3b-8&t=840s) video, as it's also where I got the function from, which I tried to convert to Obj-C.

## Using the color utils
Don't forget to import the `GcColorUtils.h`.
```objc
#import "GcUniversal/GcColorUtils.h"
```
The interface in `GcColorUtils.h` looks as follows:
```objc
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
+ (UIColor *)closestColorFromArray:(NSArray *)array toColor:(UIColor *)color ;
- (CGFloat)getColorComponent:(ColorComponent)component ;
- (CGFloat)rgbValue;
- (BOOL)isGrayscale;
@end
```
All the functions should be relativ self explanatory I think, but I will explain a few of them anyways.
The `closestColorFromArray: toColor: ;` function returns the color from the input array, which is the closest to the input color.
The `rgbValue` function returns a float between 0 and 3. This float is calcualted by adding the `r`, `g` and `b` values of the color together.

## Using the image utils
Don't forget to import the `GcColorUtils.h`.
```objc
#import "GcUniversal/GcImageUtils.h"
```
The interface in `GcImageUtils.h` looks as follows:
```objc
@interface UIImage (imageUtils)
+ (UIImage *)stockImgForBundleID:(NSString *)arg1 ;
- (UIColor *)averageColor;
- (NSArray <UIColor *> *)dominantColors;
@end
```
All of these functions should be self explanaetory though, but if you do have a question, just ask me on Twitter or something.

If you want to ask me anything about my library feel free to ask me on [Twitter](https://twitter.com/messages/compose?recipient_id=860938938910986244).
