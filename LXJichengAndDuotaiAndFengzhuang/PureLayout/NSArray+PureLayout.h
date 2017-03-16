//
//  NSArray+PureLayout.h
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


#pragma mark - NSArray+PureLayout

/**
 A category on NSArray that provides a simple yet powerful interface to:
    - Manage an array of Auto Layout constraints
    - Apply constraints to an array of views
 */
@interface NSArray (PureLayout)


#pragma mark Array of Constraints

/** Activates the constraints in this array. */
- (void)autoInstallConstraints;

/** Deactivates the constraints in this array. */
- (void)autoRemoveConstraints;

#if __PureLayout_MinBaseSDK_iOS_8_0

/** Sets the string as the identifier for the constraints in this array. Available in iOS 7.0 and OS X 10.9 and later. */
- (instancetype)autoIdentifyConstraints:(NSString *)identifier;

#endif /* __PureLayout_MinBaseSDK_iOS_8_0 */


#pragma mark Array of Views

/** Aligns views in this array to one another along a given edge. */
- (NSArray *)autoAlignViewsToEdge:(ALEdge)edge;

/** Aligns views in this array to one another along a given axis. */
- (NSArray *)autoAlignViewsToAxis:(ALAxis)axis;

/** Matches a given dimension of all the views in this array. */
- (NSArray *)autoMatchViewsDimension:(ALDimension)dimension;

/** Sets the given dimension of all the views in this array to a given size. */
- (NSArray *)autoSetViewsDimension:(ALDimension)dimension toSize:(CGFloat)size;

/** Sets all of the views in this array to a given size. */
- (NSArray *)autoSetViewsDimensionsToSize:(CGSize)size;


/** Distributes the views in this array equally along the selected axis in their superview. Views will be the same size (variable) in the dimension along the axis and will have spacing (fixed) between them. 
 *  在它们的超级视图中沿着所选择的轴均匀分布该数组中的视图。 视图将沿着轴的尺寸具有相同的大小（变量），并且它们之间将具有间隔（固定）。
 */
- (NSArray *)autoDistributeViewsAlongAxis:(ALAxis)axis
                                alignedTo:(ALAttribute)alignment
                         withFixedSpacing:(CGFloat)spacing;

/** Distributes the views in this array equally along the selected axis in their superview. Views will be the same size (variable) in the dimension along the axis and will have spacing (fixed) between them, with optional insets from the first and last views to their superview. 
 *  在它们的超级视图中沿着所选择的轴均匀分布该数组中的视图。 视图将在沿着轴的维度中具有相同的大小（变量），并且它们之间将具有间隔（固定），从其第一个和最后一个视图到其父视图的可选插入。
 */
- (NSArray *)autoDistributeViewsAlongAxis:(ALAxis)axis
                                alignedTo:(ALAttribute)alignment
                         withFixedSpacing:(CGFloat)spacing
                             insetSpacing:(BOOL)shouldSpaceInsets;

/** Distributes the views in this array equally along the selected axis in their superview. Views will have spacing (fixed) between them, with optional insets from the first and last views to their superview, and optionally constrained to the same size in the dimension along the axis. 
 *  在它们的超级视图中沿着所选择的轴均匀分布该数组中的视图。 视图将在它们之间具有间隔（固定），具有从其父视图的第一和最后视图的可选插入，并且可选地约束在沿着轴的维度中的相同大小。
 */
- (NSArray *)autoDistributeViewsAlongAxis:(ALAxis)axis
                                alignedTo:(ALAttribute)alignment
                         withFixedSpacing:(CGFloat)spacing
                             insetSpacing:(BOOL)shouldSpaceInsets
                             matchedSizes:(BOOL)shouldMatchSizes;


/** Distributes the views in this array equally along the selected axis in their superview. Views will be the same size (fixed) in the dimension along the axis and will have spacing (variable) between them. */
- (NSArray *)autoDistributeViewsAlongAxis:(ALAxis)axis
                                alignedTo:(ALAttribute)alignment
                            withFixedSize:(CGFloat)size;

/** Distributes the views in this array equally along the selected axis in their superview. Views will be the same size (fixed) in the dimension along the axis and will have spacing (variable) between them, with optional insets from the first and last views to their superview. 
 *  在它们的超级视图中沿着所选择的轴均匀分布该数组中的视图。 视图将沿着轴的尺寸具有相同的尺寸（固定），并且它们之间将具有间距（可变）。
 */
- (NSArray *)autoDistributeViewsAlongAxis:(ALAxis)axis
                                alignedTo:(ALAttribute)alignment
                            withFixedSize:(CGFloat)size
                             insetSpacing:(BOOL)shouldSpaceInsets;

@end
