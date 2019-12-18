//
//  UIApplication+JW.m
//  LJWBasicUtilites_Example
//
//  Created by 刘君威 on 2019/12/17.
//  Copyright © 2019 liujunwei. All rights reserved.
//

#import "UIApplication+JW.h"

@implementation UIApplication (JW)

- (UIViewController *)jw_currentActivityViewController {
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    
    if (window.windowLevel != UIWindowLevelNormal) {
        NSArray *windows = [[UIApplication sharedApplication] windows];
        for (UIWindow *tmpWindow in windows) {
            if (tmpWindow.windowLevel == UIWindowLevelNormal) {
                window = tmpWindow;
                break;
            }
        }
    }
    
    UIViewController *resultVC = window.rootViewController;
    
    while (resultVC.presentedViewController) {
        resultVC = resultVC.presentedViewController;
    }
    
    if ([resultVC isKindOfClass:[UITabBarController class]]) {
        resultVC = [(UITabBarController *)resultVC selectedViewController];
    }
    
    if ([resultVC isKindOfClass:[UINavigationController class]]) {
        resultVC = [(UINavigationController *)resultVC topViewController];
    }
    
    return resultVC;
}

- (void)jw_openSettingPage {
    [self openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
}

- (void)jw_telTo:(NSString *)phoneNumber {
    phoneNumber = [phoneNumber stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    NSString *str = [NSString stringWithFormat:@"telprompt://%@", phoneNumber];
    [self openURL:[NSURL URLWithString:str]];
}

- (void)jw_registerNotificationSettings {
    UIUserNotificationSettings *settings = [UIUserNotificationSettings
                                            settingsForTypes:(UIUserNotificationTypeAlert |
                                                              UIUserNotificationTypeSound |
                                                              UIUserNotificationTypeBadge)
                                            categories:nil];
    [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
}

- (BOOL)jw_allowedNotification {
    UIUserNotificationSettings *setting = [[UIApplication sharedApplication] currentUserNotificationSettings];
    if (setting.types != UIUserNotificationTypeNone) {
        return YES;
    }
    return NO;
}

- (void)jw_openNotificationSettings {
    NSString *url = nil;
    url = UIApplicationOpenSettingsURLString;
    
    if ([self canOpenURL:[NSURL URLWithString:url]]) {
        if (@available(iOS 10.0, *)) {
            [self openURL:[NSURL URLWithString:url] options:@{} completionHandler:nil];
        } else {
            [self openURL:[NSURL URLWithString:url]];
        }
    }
}

- (void)jw_openAppStoreWithAppId:(NSString *)appId {
    NSString *appStoreString = [NSString stringWithFormat:@"itms-apps://itunes.apple.com/app/id%@", appId];
    [self openURL:[NSURL URLWithString:appStoreString]];
}

- (void)jw_openAppStoreReviewsWithAppId:(NSString *)appId {
    NSString *str = [NSString stringWithFormat:@"itms-apps://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%@", appId];
     [self openURL:[NSURL URLWithString:str]];
}

@end
