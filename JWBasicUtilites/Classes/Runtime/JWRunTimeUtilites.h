//
//  JWRunTimeUtilites.h
//  LJWBasicUtilites_Example
//
//  Created by 刘君威 on 2019/12/17.
//  Copyright © 2019 liujunwei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>


/// 类方法替换
/// @param aClass 类
/// @param originSelector 被替换的原方法
/// @param swizzSelector 替换的新方法
FOUNDATION_EXPORT void JWSwizzMethod(Class aClass, SEL originSelector, SEL swizzSelector);

NS_ASSUME_NONNULL_BEGIN

@interface JWRunTimeUtilites : NSObject

+ (NSDictionary *)propertiesForClass:(Class)aClass;

+ (NSString *)propertyTypeName:(objc_property_t)property;

#pragma mark - BOOL

+ (BOOL)propertyIsObject:(objc_property_t)property;
+ (BOOL)propertyIsWeak:(objc_property_t)property;
+ (BOOL)propertyIsStrong:(objc_property_t)property;
+ (BOOL)propertyIsCopy:(objc_property_t)property;
+ (BOOL)propertyIsAssign:(objc_property_t)property;
+ (BOOL)propertyIsReadOnly:(objc_property_t)property;

@end

NS_ASSUME_NONNULL_END
