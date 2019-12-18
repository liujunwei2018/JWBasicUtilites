//
//  UIApplication+JW.h
//  LJWBasicUtilites_Example
//
//  Created by 刘君威 on 2019/12/17.
//  Copyright © 2019 liujunwei. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIApplication (JW)

// 获取当前活跃的UIViewController
- (UIViewController *)jw_currentActivityViewController;

// 打开App的系统设置面板
- (void)jw_openSettingPage;

// 拨打电话
- (void)jw_telTo:(NSString *)phoneNumber;

// 注册推送通知
- (void)jw_registerNotificationSettings;

// 是否开启推送通知
- (BOOL)jw_allowedNotification;

// 打开系统推送通知设置页面
- (void)jw_openNotificationSettings;

// 打开app在appStore的主页面
- (void)jw_openAppStoreWithAppId:(NSString *)appId;

// 打开app在appStore的评价页面
- (void)jw_openAppStoreReviewsWithAppId:(NSString *)appId;
@end

NS_ASSUME_NONNULL_END
