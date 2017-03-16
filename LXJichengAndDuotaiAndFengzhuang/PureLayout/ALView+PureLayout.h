//
//  ALView+PureLayout.h
//  v2.0.5
//  https://github.com/smileyborg/PureLayout
//
//  Copyright (c) 2012 Richard Turton
//  Copyright (c) 2013-2015 Tyler Fox
//
//  This code is distributed under the terms and conditions of the MIT license.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to
//  deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
//  sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//

#import "PureLayoutDefines.h"


#pragma mark - ALView+PureLayout

/**
 A category on UIView/NSView that provides a simple yet powerful interface for creating Auto Layout constraints.
 */
@interface ALView (PureLayout)


#pragma mark Factory & Initializer Methods

/** Creates and returns a new view that does not convert the autoresizing mask into constraints. */
+ (instancetype)newAutoLayoutView;

/** Initializes and returns a new view that does not convert the autoresizing mask into constraints. */
- (instancetype)initForAutoLayout;


#pragma mark Create Constraints Without Installing

/** Prevents constraints created in the given constraints block from being automatically installed (activated).
    The constraints created from calls to the PureLayout API in the block are returned in a single array. */
+ (NSArray *)autoCreateConstraintsWithoutInstalling:(ALConstraintsBlock)block;


#pragma mark Set Priority For Constraints

/** Sets the constraint priority to the given value for all constraints created using the PureLayout API within the given constraints block.
    NOTE: This method will have no effect (and will NOT set the priority) on constraints created or added without using the PureLayout API! */
+ (void)autoSetPriority:(ALLayoutPriority)priority forConstraints:(ALConstraintsBlock)block;


#pragma mark Set Identifier For Constraints

#if __PureLayout_MinBaseSDK_iOS_8_0

/** Sets the identifier for all constraints created using the PureLayout API within the given constraints block.
    NOTE: This method will have no effect (and will NOT set the identifier) on constraints created or added without using the PureLayout API! */
+ (void)autoSetIdentifier:(NSString *)identifier forConstraints:(ALConstraintsBlock)block;

#endif /* __PureLayout_MinBaseSDK_iOS_8_0 */


#pragma mark Center & Align in Superview

/**
 *  Centers the view in its superview.
 *  将视图放在其superview中心。
 */
- (NSArray *)autoCenterInSuperview;

/**
 *  Aligns the view to the same axis of its superview.
 *  将视图对齐到其superview的同一轴。
 */
- (NSLayoutConstraint *)autoAlignAxisToSuperviewAxis:(ALAxis)axis;

#if __PureLayout_MinBaseSDK_iOS_8_0

/**
 *  Centers the view in its superview's margins. Available in iOS 8.0 and later.
 *  将视图置于其超级边距的中心。 适用于iOS 8.0及更高版本。
 */
- (NSArray *)autoCenterInSuperviewMargins;

/** 
 *  Aligns the view to the corresponding margin axis of its superview. Available in iOS 8.0 and later. 
 *  将视图对齐到其superview的相应边缘轴。 适用于iOS 8.0及更高版本。
 */
- (NSLayoutConstraint *)autoAlignAxisToSuperviewMarginAxis:(ALAxis)axis;

#endif /* __PureLayout_MinBaseSDK_iOS_8_0 */


#pragma mark Pin Edges to Superview 将边缘固定到父视图

/** 
 *  Pins the given edge of the view to the same edge of its superview.
 *  将视图的给定边缘固定到其superview的相同边缘。
 */
- (NSLayoutConstraint *)autoPinEdgeToSuperviewEdge:(ALEdge)edge;

/** Pins the given edge of the view to the same edge of its superview with an inset. 
 *  将视图的给定边缘插入其父视图的相同边缘。
 */
- (NSLayoutConstraint *)autoPinEdgeToSuperviewEdge:(ALEdge)edge withInset:(CGFloat)inset;

/** Pins the given edge of the view to the same edge of its superview with an inset as a maximum or minimum. 
 *  将视图的给定边缘以其插入为最大值或最小值插入其超级视图的相同边缘。
 */
- (NSLayoutConstraint *)autoPinEdgeToSuperviewEdge:(ALEdge)edge withInset:(CGFloat)inset relation:(NSLayoutRelation)relation;

/** Pins the edges of the view to the edges of its superview with the given edge insets. 
 *  使用给定的边缘插入将视图的边缘固定到其超级视图的边缘
 */
- (NSArray *)autoPinEdgesToSuperviewEdgesWithInsets:(ALEdgeInsets)insets;

/** Pins 3 of the 4 edges of the view to the edges of its superview with the given edge insets, excluding one edge. 
 *  将视图的4个边缘中的3个边缘与其给定边缘插入的其超级边缘的边缘对齐，排除一个边缘。
 */
- (NSArray *)autoPinEdgesToSuperviewEdgesWithInsets:(ALEdgeInsets)insets excludingEdge:(ALEdge)edge;

#if __PureLayout_MinBaseSDK_iOS_8_0

/** Pins the given edge of the view to the corresponding margin of its superview. Available in iOS 8.0 and later. 
 *  将视图的给定边缘绑定到其父视图的对应边缘。 适用于iOS 8.0及更高版本。
 */
- (NSLayoutConstraint *)autoPinEdgeToSuperviewMargin:(ALEdge)edge;

/** Pins the given edge of the view to the corresponding margin of its superview as a maximum or minimum. Available in iOS 8.0 and later. 
 *  将视图的给定边缘作为其最大或最小的其父视图的对应边缘。 适用于iOS 8.0及更高版本。
 */
- (NSLayoutConstraint *)autoPinEdgeToSuperviewMargin:(ALEdge)edge relation:(NSLayoutRelation)relation;

/** Pins the edges of the view to the margins of its superview. Available in iOS 8.0 and later. 
 *  将视图的边缘固定到其superview的边缘。 适用于iOS 8.0及更高版本。
 */
- (NSArray *)autoPinEdgesToSuperviewMargins;

/** Pins 3 of the 4 edges of the view to the margins of its superview excluding one edge. Available in iOS 8.0 and later. 
 *  将视图的4个边缘中的3个对齐到其超级视图的边距，不包括一个边。 适用于iOS 8.0及更高版本。
 */
- (NSArray *)autoPinEdgesToSuperviewMarginsExcludingEdge:(ALEdge)edge;

#endif /* __PureLayout_MinBaseSDK_iOS_8_0 */


#pragma mark Pin Edges

/** Pins an edge of the view to a given edge of another view. 
 *  将视图的边缘固定到另一个视图的给定边。
 */
- (NSLayoutConstraint *)autoPinEdge:(ALEdge)edge toEdge:(ALEdge)toEdge ofView:(ALView *)otherView;

/** Pins an edge of the view to a given edge of another view with an offset. 
 *  将视图的边缘与另一个具有偏移的视图的给定边缘对齐。
 */
- (NSLayoutConstraint *)autoPinEdge:(ALEdge)edge toEdge:(ALEdge)toEdge ofView:(ALView *)otherView withOffset:(CGFloat)offset;

/** Pins an edge of the view to a given edge of another view with an offset as a maximum or minimum. 
 *  将视图的边缘以偏移量作为最大值或最小值插入另一视图的给定边缘。
 */
- (NSLayoutConstraint *)autoPinEdge:(ALEdge)edge toEdge:(ALEdge)toEdge ofView:(ALView *)otherView withOffset:(CGFloat)offset relation:(NSLayoutRelation)relation;


#pragma mark Align Axes

/** Aligns an axis of the view to the same axis of another view. 
 *  将视图的轴与另一个视图的同一轴对齐。
 */
- (NSLayoutConstraint *)autoAlignAxis:(ALAxis)axis toSameAxisOfView:(ALView *)otherView;

/** Aligns an axis of the view to the same axis of another view with an offset. 
 *  将视图的轴与另一个视图的具有偏移的轴对齐。
 */
- (NSLayoutConstraint *)autoAlignAxis:(ALAxis)axis toSameAxisOfView:(ALView *)otherView withOffset:(CGFloat)offset;


#pragma mark Match Dimensions

/** Matches a dimension of the view to a given dimension of another view. 
 *  将视图的维度与另一个视图的给定维度匹配
 */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(ALView *)otherView;

/** Matches a dimension of the view to a given dimension of another view with an offset. 
 *  将视图的维度与具有偏移量的另一个视图的给定维度匹配。
 */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(ALView *)otherView withOffset:(CGFloat)offset;

/** Matches a dimension of the view to a given dimension of another view with an offset as a maximum or minimum. 
 *  将视图的维度与另一个视图的给定维度匹配，将偏移量作为最大值或最小值。
 */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(ALView *)otherView withOffset:(CGFloat)offset relation:(NSLayoutRelation)relation;

/** Matches a dimension of the view to a multiple of a given dimension of another view. 
 *  将视图的维度与另一个视图的给定维度的倍数匹配。
 */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(ALView *)otherView withMultiplier:(CGFloat)multiplier;

/** Matches a dimension of the view to a multiple of a given dimension of another view as a maximum or minimum. 
 *  将视图的维度与另一个视图的给定维度的倍数匹配为最大值或最小值。
 */
- (NSLayoutConstraint *)autoMatchDimension:(ALDimension)dimension toDimension:(ALDimension)toDimension ofView:(ALView *)otherView withMultiplier:(CGFloat)multiplier relation:(NSLayoutRelation)relation;


#pragma mark Set Dimensions

/** Sets the view to a specific size. 
 *  将视图设置为特定大小。
 */
- (NSArray *)autoSetDimensionsToSize:(CGSize)size;

/** Sets the given dimension of the view to a specific size. 
 *  将视图的给定维度设置为特定大小。
 */
- (NSLayoutConstraint *)autoSetDimension:(ALDimension)dimension toSize:(CGFloat)size;

/** Sets the given dimension of the view to a specific size as a maximum or minimum. 
 *  将视图的给定维度设置为特定大小作为最大值或最小值。
 */
- (NSLayoutConstraint *)autoSetDimension:(ALDimension)dimension toSize:(CGFloat)size relation:(NSLayoutRelation)relation;


#pragma mark Set Content Compression Resistance & Hugging

/** Sets the priority of content compression resistance for an axis.
    NOTE: This method must be called from within the block passed into the method +[UIView autoSetPriority:forConstraints:] 
 *  设置轴的内容压缩电阻的优先级。
      注意：这个方法必须从块内调用传递给方法+ [UIView autoSetPriority：forConstraints：]
 */
- (void)autoSetContentCompressionResistancePriorityForAxis:(ALAxis)axis;

/** Sets the priority of content hugging for an axis.
    NOTE: This method must be called from within the block passed into the method +[UIView autoSetPriority:forConstraints:] 
 *  设置轴的内容拥抱的优先级。
      注意：这个方法必须从块内调用传递给方法+ [UIView autoSetPriority：forConstraints：]
 */
- (void)autoSetContentHuggingPriorityForAxis:(ALAxis)axis;


#pragma mark Constrain Any Attributes

/** Constrains an attribute of the view to a given attribute of another view. 
 *  将视图的属性限制到另一个视图的给定属性。
 */
- (NSLayoutConstraint *)autoConstrainAttribute:(ALAttribute)attribute toAttribute:(ALAttribute)toAttribute ofView:(ALView *)otherView;

/** Constrains an attribute of the view to a given attribute of another view with an offset.
 *  将视图的属性限制为具有偏移量的另一个视图的给定属性。
 */
- (NSLayoutConstraint *)autoConstrainAttribute:(ALAttribute)attribute toAttribute:(ALAttribute)toAttribute ofView:(ALView *)otherView withOffset:(CGFloat)offset;

/** Constrains an attribute of the view to a given attribute of another view with an offset as a maximum or minimum. 
 *  将视图的属性限制为具有作为最大值或最小值的偏移的另一视图的给定属性。
 */
- (NSLayoutConstraint *)autoConstrainAttribute:(ALAttribute)attribute toAttribute:(ALAttribute)toAttribute ofView:(ALView *)otherView withOffset:(CGFloat)offset relation:(NSLayoutRelation)relation;

/** Constrains an attribute of the view to a given attribute of another view with a multiplier. 
 *  使用乘数将视图的属性限制到另一个视图的给定属性。
 */
- (NSLayoutConstraint *)autoConstrainAttribute:(ALAttribute)attribute toAttribute:(ALAttribute)toAttribute ofView:(ALView *)otherView withMultiplier:(CGFloat)multiplier;

/** Constrains an attribute of the view to a given attribute of another view with a multiplier as a maximum or minimum.
 *  将视图的属性限制为另一个视图的给定属性，其乘数为最大值或最小值
 */
- (NSLayoutConstraint *)autoConstrainAttribute:(ALAttribute)attribute toAttribute:(ALAttribute)toAttribute ofView:(ALView *)otherView withMultiplier:(CGFloat)multiplier relation:(NSLayoutRelation)relation;


#pragma mark Pin to Layout Guides (iOS only)

#if TARGET_OS_IPHONE

/** Pins the top edge of the view to the top layout guide of the given view controller with an inset. Available on iOS only. 
 *  将视图的顶部边缘插入给定视图控制器的顶部布局指南，带有插入。 仅在iOS上可用。
 */
- (NSLayoutConstraint *)autoPinToTopLayoutGuideOfViewController:(UIViewController *)viewController withInset:(CGFloat)inset;

/** Pins the top edge of the view to the top layout guide of the given view controller with an inset as a maximum or minimum. Available on iOS only. 
 *  将视图的顶部边缘以给定视图控制器的顶部布局指南作为最大值或最小值插入。 仅在iOS上可用。
 */
- (NSLayoutConstraint *)autoPinToTopLayoutGuideOfViewController:(UIViewController *)viewController withInset:(CGFloat)inset relation:(NSLayoutRelation)relation;

/** Pins the bottom edge of the view to the bottom layout guide of the given view controller with an inset. Available on iOS only. 
 *  将视图的底部边缘插入给定视图控制器的底部布局指南，使用插入。 仅在iOS上可用。
 */
- (NSLayoutConstraint *)autoPinToBottomLayoutGuideOfViewController:(UIViewController *)viewController withInset:(CGFloat)inset;

/** Pins the bottom edge of the view to the bottom layout guide of the given view controller with an inset as a maximum or minimum. Available on iOS only. 
 *  将视图的底部边缘以插入为最大值或最小值插入给定视图控制器的底部布局指南。 仅在iOS上可用。
 */
- (NSLayoutConstraint *)autoPinToBottomLayoutGuideOfViewController:(UIViewController *)viewController withInset:(CGFloat)inset relation:(NSLayoutRelation)relation;

#endif /* TARGET_OS_IPHONE */


#pragma mark Deprecated Methods

/** DEPRECATED as of PureLayout v2.0.0. Retain a reference to and remove specific constraints instead, or recreate the view(s) entirely to remove all constraints.
    Removes all explicit constraints that affect the view.
    WARNING: Apple's constraint solver is not optimized for large-scale constraint removal; you may encounter major performance issues after using this method.
    NOTE: This method preserves implicit constraints, such as intrinsic content size constraints, which you usually do not want to remove. 
 *  DEPRECATED自PureLayout v2.0.0起。 保留对特定约束的引用，或者完全重新创建视图以删除所有约束。
      删除影响视图的所有显式约束。
      警告：苹果的约束求解器没有针对大规模约束去除进行优化; 您可能在使用此方法后遇到主要性能问题。
      注意：此方法保留隐式约束，例如内部内容大小约束，您通常不想删除它。
 */
- (void)autoRemoveConstraintsAffectingView __attribute__((deprecated));

/** DEPRECATED as of PureLayout v2.0.0. Retain a reference to and remove specific constraints instead, or recreate the view(s) entirely to remove all constraints.
    Removes all constraints that affect the view, optionally including implicit constraints.
    WARNING: Apple's constraint solver is not optimized for large-scale constraint removal; you may encounter major performance issues after using this method.
    NOTE: Implicit constraints are auto-generated lower priority constraints, and you usually do not want to remove these. 
 *  DEPRECATED自PureLayout v2.0.0起。 保留对特定约束的引用，或者完全重新创建视图以删除所有约束。
      删除影响视图的所有约束，可选择包括隐式约束。
      警告：苹果的约束求解器没有针对大规模约束去除进行优化; 您可能在使用此方法后遇到主要性能问题。
      注意：隐式约束是自动生成的优先级较低的约束，您通常不想删除这些约束。
 */
- (void)autoRemoveConstraintsAffectingViewIncludingImplicitConstraints:(BOOL)shouldRemoveImplicitConstraints __attribute__((deprecated));

/** DEPRECATED as of PureLayout v2.0.0. Retain a reference to and remove specific constraints instead, or recreate the view(s) entirely to remove all constraints.
    Recursively removes all explicit constraints that affect the view and its subviews.
    WARNING: Apple's constraint solver is not optimized for large-scale constraint removal; you may encounter major performance issues after using this method.
    NOTE: This method preserves implicit constraints, such as intrinsic content size constraints, which you usually do not want to remove. 
 *  DEPRECATED自PureLayout v2.0.0起。 保留对特定约束的引用，或者完全重新创建视图以删除所有约束。
      递归地删除影响视图及其子视图的所有显式约束。
      警告：苹果的约束求解器没有针对大规模约束去除进行优化; 您可能在使用此方法后遇到主要性能问题。
      注意：此方法保留隐式约束，例如内部内容大小约束，您通常不想删除它。
 */
- (void)autoRemoveConstraintsAffectingViewAndSubviews __attribute__((deprecated));

/** DEPRECATED as of PureLayout v2.0.0. Retain a reference to and remove specific constraints instead, or recreate the view(s) entirely to remove all constraints.
    Recursively removes all constraints from the view and its subviews, optionally including implicit constraints.
    WARNING: Apple's constraint solver is not optimized for large-scale constraint removal; you may encounter major performance issues after using this method.
    NOTE: Implicit constraints are auto-generated lower priority constraints, and you usually do not want to remove these. 
 *  DEPRECATED自PureLayout v2.0.0起。 保留对特定约束的引用，或者完全重新创建视图以删除所有约束。
      递归地从视图及其子视图中删除所有约束，可选地包括隐式约束。
      警告：苹果的约束求解器没有针对大规模约束去除进行优化; 您可能在使用此方法后遇到主要性能问题。
      注意：隐式约束是自动生成的优先级较低的约束，您通常不想删除这些约束。
 */
- (void)autoRemoveConstraintsAffectingViewAndSubviewsIncludingImplicitConstraints:(BOOL)shouldRemoveImplicitConstraints __attribute__((deprecated));

@end
