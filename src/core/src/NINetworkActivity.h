//
// Copyright 2011 Jeff Verkoeyen
//
// Forked from Three20 July 2, 2011 - Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

/**
 * For showing network activity in the device's status bar.
 *
 * @ingroup NimbusCore
 * @defgroup Network-Activity Network Activity
 * @{
 *
 * Two methods for keeping track of all active network tasks. These methods are threadsafe
 * and act as a simple counter. When the counter is positive, the network activity indicator
 * is displayed.
 */

/**
 * Increment the number of active network tasks.
 *
 * The status bar activity indicator will be spinning while there are active tasks.
 *
 * This method is threadsafe.
 */
void NINetworkActivityTaskDidStart();

/**
 * Decrement the number of active network tasks.
 *
 * The status bar activity indicator will be spinning while there are active tasks.
 *
 * This method is threadsafe.
 */
void NINetworkActivityTaskDidFinish();

/**
 * @name For Debugging Only
 * @{
 */
#ifdef DEBUG

/**
 * Enable network activity debugging.
 *
 *      @attention This is only available if the DEBUG preprocessor macro is defined.
 *
 * The Nimbus network activity methods will only work correctly if they are the only methods to
 * touch networkActivityIndicatorVisible. If you are using another library that touches
 * networkActivityIndicatorVisible then the network activity indicator might not accurately
 * represent its state.
 *
 * When enabled, the networkActivityIndicatorVisible method on UIApplication will be swizzled
 * with a debugging method that checks the global network task count and verifies that state
 * is maintained correctly. If it is found that networkActivityIndicatorVisible is being accessed
 * directly, then an assertion will be fired.
 *
 * If debugging was previously enabled, this does nothing.
 */
void NIEnableNetworkActivityDebugging();

/**
 * Disable network activity debugging.
 *
 *      @attention This is only available if the DEBUG preprocessor macro is defined.
 *
 * When disabled, the networkActivityIndicatorVisible will be restored if this was previously
 * enabled, otherwise this method does nothing.
 *
 * If debugging wasn't previously enabled, this does nothing.
 */
void NIDisableNetworkActivityDebugging();

#endif

/**@}*/// End of For Debugging Only


///////////////////////////////////////////////////////////////////////////////////////////////////
/**@}*/// End of Network Activity /////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
