//
//  UIDevice+JW.h
//  LJWBasicUtilites_Example
//
//  Created by 刘君威 on 2019/12/17.
//  Copyright © 2019 liujunwei. All rights reserved.
//

#import <UIKit/UIKit.h>

// 手机网络类型
typedef NS_ENUM(NSInteger, JWNetworkType) {
    JWNetworkTypeUnReachable,
    JWNetworkTypeWifi,
    JWNetworkTypeOther,
    JWNetworkType2G,
    JWNetworkType3G,
    JWNetworkType4G
};

NS_ASSUME_NONNULL_BEGIN

@interface UIDevice (JW)

// 获取手机网络类型
- (JWNetworkType)jw_networkType;

// 手机型号
- (NSString *)jw_phoneType;

// 运营商
- (NSString *)jw_OperatorInfo;

// 获取idfa
- (NSString *)jw_idfaString;

// 获取idfv
- (NSString *)jw_idfvString;

// mac地址
- (NSString *)jw_macAddress;

/**
 获取 UUID

 @return 返回
 */
- (NSString *)jw_uuid;
@end

NS_ASSUME_NONNULL_END
