/*
 * Copyright (c) 2016 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if !defined(_VIEW_H)
#define _VIEW_H

#define GRP_MAIN "main"

/*
 * Create a view
 */
void print_debug(int x, int y);
void print_debugf(float x);
void error(char *msg);
void eprint(char *msg);
int send_udp_one(void);
void eprint(char *msg);
int send_udp(float x);
int init_udp(void);
void print_debugf(float x);
#endif
