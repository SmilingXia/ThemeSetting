//
//  ZDYHomeVC.m
//  LXJichengAndDuotaiAndFengzhuang
//
//  Created by xia on 2017/3/14.
//  Copyright © 2017年 cn.bkw. All rights reserved.
//

#import "ZDYHomeVC.h"
#import "ZDYSetUpVC.h"

@interface ZDYHomeVC ()

@end

@implementation ZDYHomeVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.centerTitleLable.text = @"首页";
    [self displayWidthLeftButton:YES andWidthRightButton:NO];
    [self.rightButton setTitle:@"设置" forState:UIControlStateNormal];
}

- (void)rightButtonOnclick:(UIButton *)sender{
    ZDYSetUpVC *vc = [[ZDYSetUpVC alloc] init];
    [self presentViewController:vc animated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

@end
