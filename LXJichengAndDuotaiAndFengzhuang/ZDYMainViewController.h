//
//  ZDYMainViewController.h
//  LXJichengAndDuotaiAndFengzhuang
//
//  Created by xia on 2017/3/14.
//  Copyright © 2017年 cn.bkw. All rights reserved.
//

#define Bar_View_Heigth 60
//block回调weak
#define WEAK_SELF __weak typeof(self) weakSelf = self
#define STRONG_SELF __strong typeof(self) strongSelf = weakSelf

#import <UIKit/UIKit.h>
#import "PureLayout.h"
#import "ZDYThemeStyleClass.h"
#import "ZDYNotificationCenter.h"

@interface ZDYMainViewController : UIViewController

@property (nonatomic, strong) UILabel *centerTitleLable;
@property (nonatomic, strong) UIButton *leftButton;
@property (nonatomic, strong) UIButton *rightButton;

/**
 *  右边视图的点击事件
 */
- (void)rightButtonOnclick:(UIButton *)sender;

/**
 *  是否显示左右视图 (yes - 隐藏) (no - 显示)
 */
- (void)displayWidthLeftButton:(BOOL)isDisplayLeftButton andWidthRightButton:(BOOL)isDisplayRightButton;


@end
