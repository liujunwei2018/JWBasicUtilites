//
//  JWBasicMacros_h.h
//  LJWBasicUtilites
//
//  Created by 刘君威 on 2019/12/17.
//  Copyright © 2019 liujunwei. All rights reserved.
//

#ifndef JWBasicMacros_h
#define JWBasicMacros_h

#import <Foundation/Foundation.h>

// 客户端App版本号
#define kJWClientVersion                   [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

// System Size
#define kJWScreenBounds                    ([UIScreen mainScreen].bounds)
#define kJWScreenHeight                    ([UIScreen mainScreen].bounds.size.height)
#define kJWScreenWidth                     ([UIScreen mainScreen].bounds.size.width)
#define kJWScreenScale                     ([UIScreen mainScreen].scale)
#define kJWSingleLineHeight                (1.f / [UIScreen mainScreen].scale)
#define kJWStatusBarHeight                 [UIApplication sharedApplication].statusBarFrame.size.height
#define kJWNavigationBarHeight             (44.f)
#define kJWNavigationAndStatusBarHeight    (kJWStatusBarHeight + kJWNavigationBarHeight)
#define kJWTableViewBottomButtonHeight     (56.f)
#define kJWScreenSafeBottomHeight \
({ \
    CGFloat bottom = 0.f; \
    if(@available(iOS 11.0, *)) { \
        bottom = [UIApplication sharedApplication].keyWindow.safeAreaInsets.bottom; \
    } \
    (bottom); \
})
#define kJWTabBarHeight                    (kJWScreenSafeBottomHeight + 49.f)
#define kJWScreenRealWidth                 kJWScreenWidth * kJWScreenScale
#define kJWScreenRealHeight                kJWScreenHeight * kJWScreenScale

#define kJWScreenAutoLayoutScale           (kJWScreenWidth / 375)
#define kJWScreenAutoLayoutScaleCeil(x)    ceilf(kJWScreenAutoLayoutScale*(x))
#define kJWScreenAutoWitdh(x)              (kJWScreenAutoLayoutScale*(x))
#define kJWScreenAutoHeight(x)             ((kJWScreenHeight / 667) * (x))

// iPhone X系列
#define kJWScreenIsIPhoneX                 (kJWScreenSafeBottomHeight ? YES : NO)

// 图片
#define kJWImage(name)                     [UIImage imageNamed:name]

// 常用字体颜色
#define kJWTextColorDefult                 [UIColor colorWithRed:51/255.0 green:51/255.0 blue:51/255.0 alpha:1]
#define kJWTextColorDeepGary               [UIColor colorWithRed:102/255.0 green:102/255.0 blue:102/255.0 alpha:1]
#define kJWTextColorGary                   [UIColor colorWithRed:153/255.0 green:153/255.0 blue:153/255.0 alpha:1]

// 常用颜色
#define kJWGaryBackgroundColor             [UIColor colorWithRed:242/255.0 green:244/255.0 blue:246/255.0 alpha:1]
#define kJWGaryLineColor                   [UIColor colorWithWhite:0 alpha:0.08]

// 操作系统版本号
#define kJWCurrentSystemVersion            [[UIDevice currentDevice] systemVersion]

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

// DEBUG日志
#ifdef DEBUG
#define JWLog(s,...) NSLog(@"<%p %@:(%d)>\n  %s\n  %@\n\n", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, __func__, [NSString stringWithFormat:(s), ##__VA_ARGS__])
#else
#define JWLog(s,...)
#endif

#endif /* JWBasicMacros_h */
