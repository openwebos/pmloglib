/* @@@LICENSE
 *
 *      Copyright (c) 2013 LG Electronics, Inc.
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
 *
 * LICENSE@@@
 */

#define _PmLogMsgKV0(ctx, level_suffix, msgid, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 0, \
        NULL, \
        NULL, \
        free_text_fmt, free_text_fmt, ## __VA_ARGS__)

#define _PmLogMsgKV1(ctx, level_suffix, msgid, k1, f1, v1, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 1, \
        k1, \
        f1, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 "} " free_text_fmt, \
        v1, ## __VA_ARGS__)

#define _PmLogMsgKV2(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 2, \
        k1 "\001" k2, \
        f1 "\001" f2, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 "} " free_text_fmt, \
        v1, v2, ## __VA_ARGS__)

#define _PmLogMsgKV3(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, k3, f3, v3, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 3, \
        k1 "\001" k2 "\001" k3, \
        f1 "\001" f2 "\001" f3, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 ","  "\"" k3 "\":" f3 "} " free_text_fmt, \
        v1, v2, v3, ## __VA_ARGS__)

#define _PmLogMsgKV4(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, k3, f3, v3, k4, f4, v4, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 4, \
        k1 "\001" k2 "\001" k3 "\001" k4, \
        f1 "\001" f2 "\001" f3 "\001" f4, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 ","  "\"" k3 "\":" f3 ","  "\"" k4 "\":" f4 "} " free_text_fmt, \
        v1, v2, v3, v4, ## __VA_ARGS__)

#define _PmLogMsgKV5(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, k3, f3, v3, k4, f4, v4, k5, f5, v5, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 5, \
        k1 "\001" k2 "\001" k3 "\001" k4 "\001" k5, \
        f1 "\001" f2 "\001" f3 "\001" f4 "\001" f5, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 ","  "\"" k3 "\":" f3 ","  "\"" k4 "\":" f4 ","  "\"" k5 "\":" f5 "} " free_text_fmt, \
        v1, v2, v3, v4, v5, ## __VA_ARGS__)

#define _PmLogMsgKV6(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, k3, f3, v3, k4, f4, v4, k5, f5, v5, k6, f6, v6, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 6, \
        k1 "\001" k2 "\001" k3 "\001" k4 "\001" k5 "\001" k6, \
        f1 "\001" f2 "\001" f3 "\001" f4 "\001" f5 "\001" f6, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 ","  "\"" k3 "\":" f3 ","  "\"" k4 "\":" f4 ","  "\"" k5 "\":" f5 ","  "\"" k6 "\":" f6 "} " free_text_fmt, \
        v1, v2, v3, v4, v5, v6, ## __VA_ARGS__)

#define _PmLogMsgKV7(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, k3, f3, v3, k4, f4, v4, k5, f5, v5, k6, f6, v6, k7, f7, v7, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 7, \
        k1 "\001" k2 "\001" k3 "\001" k4 "\001" k5 "\001" k6 "\001" k7, \
        f1 "\001" f2 "\001" f3 "\001" f4 "\001" f5 "\001" f6 "\001" f7, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 ","  "\"" k3 "\":" f3 ","  "\"" k4 "\":" f4 ","  "\"" k5 "\":" f5 ","  "\"" k6 "\":" f6 ","  "\"" k7 "\":" f7 "} " free_text_fmt, \
        v1, v2, v3, v4, v5, v6, v7, ## __VA_ARGS__)

#define _PmLogMsgKV8(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, k3, f3, v3, k4, f4, v4, k5, f5, v5, k6, f6, v6, k7, f7, v7, k8, f8, v8, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 8, \
        k1 "\001" k2 "\001" k3 "\001" k4 "\001" k5 "\001" k6 "\001" k7 "\001" k8, \
        f1 "\001" f2 "\001" f3 "\001" f4 "\001" f5 "\001" f6 "\001" f7 "\001" f8, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 ","  "\"" k3 "\":" f3 ","  "\"" k4 "\":" f4 ","  "\"" k5 "\":" f5 ","  "\"" k6 "\":" f6 ","  "\"" k7 "\":" f7 ","  "\"" k8 "\":" f8 "} " free_text_fmt, \
        v1, v2, v3, v4, v5, v6, v7, v8, ## __VA_ARGS__)

#define _PmLogMsgKV9(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, k3, f3, v3, k4, f4, v4, k5, f5, v5, k6, f6, v6, k7, f7, v7, k8, f8, v8, k9, f9, v9, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 9, \
        k1 "\001" k2 "\001" k3 "\001" k4 "\001" k5 "\001" k6 "\001" k7 "\001" k8 "\001" k9, \
        f1 "\001" f2 "\001" f3 "\001" f4 "\001" f5 "\001" f6 "\001" f7 "\001" f8 "\001" f9, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 ","  "\"" k3 "\":" f3 ","  "\"" k4 "\":" f4 ","  "\"" k5 "\":" f5 ","  "\"" k6 "\":" f6 ","  "\"" k7 "\":" f7 ","  "\"" k8 "\":" f8 ","  "\"" k9 "\":" f9 "} " free_text_fmt, \
        v1, v2, v3, v4, v5, v6, v7, v8, v9, ## __VA_ARGS__)

#define _PmLogMsgKV10(ctx, level_suffix, msgid, k1, f1, v1, k2, f2, v2, k3, f3, v3, k4, f4, v4, k5, f5, v5, k6, f6, v6, k7, f7, v7, k8, f8, v8, k9, f9, v9, k10, f10, v10, free_text_fmt, ...) \
    _PmLogMsgKV( \
        ctx, kPmLogLevel_##level_suffix, 0, msgid, 10, \
        k1 "\001" k2 "\001" k3 "\001" k4 "\001" k5 "\001" k6 "\001" k7 "\001" k8 "\001" k9 "\001" k10, \
        f1 "\001" f2 "\001" f3 "\001" f4 "\001" f5 "\001" f6 "\001" f7 "\001" f8 "\001" f9 "\001" f10, \
        free_text_fmt, \
        "{"  "\"" k1 "\":" f1 ","  "\"" k2 "\":" f2 ","  "\"" k3 "\":" f3 ","  "\"" k4 "\":" f4 ","  "\"" k5 "\":" f5 ","  "\"" k6 "\":" f6 ","  "\"" k7 "\":" f7 ","  "\"" k8 "\":" f8 ","  "\"" k9 "\":" f9 ","  "\"" k10 "\":" f10 "} " free_text_fmt, \
        v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, ## __VA_ARGS__)

#if 0
# This file was generated by this Python script:
#
#/usr/bin/python

max_kv_pairs = 10
flags = 0
log_message_delimiter = ' '

import sys
f = sys.stdout

f.write('#define _PmLogMsgKV0(ctx, level_suffix, msgid, free_text_fmt, ...) \\\n')
f.write('    _PmLogMsgKV( \\\n')
f.write('        ctx, kPmLogLevel_##level_suffix, {0}, msgid, 0, \\\n'.format(flags))
f.write('        NULL, \\\n')
f.write('        NULL, \\\n')
f.write('        free_text_fmt, free_text_fmt, ## __VA_ARGS__)\n')

for i in range(1, max_kv_pairs+1):
        f.write('\n')
        f.write('#define _PmLogMsgKV{0}(ctx, level_suffix, msgid, '.format(i))
        for j in range(1, i+1):
             f.write('k{0}, f{0}, v{0}, '.format(j))
        f.write('free_text_fmt, ...) \\\n')

        f.write('    _PmLogMsgKV( \\\n')
        f.write('        ctx, kPmLogLevel_##level_suffix, {0}, msgid, {1}, \\\n'.format(flags, i))

        f.write('        k1')
        for j in range(2, i+1):
            f.write(' "\\001" k{0}'.format(j))
        f.write(', \\\n')

        f.write('        f1')
        for j in range(2, i+1):
            f.write(' "\\001" f{0}'.format(j))
        f.write(', \\\n')

        f.write('        free_text_fmt, \\\n')

        f.write('        "{" ')
        for j in range(1, i):
            f.write(' "\\"" k{0} "\\":" f{0} "," '.format(j))
        f.write(' "\\"" k{0} "\\":" f{0} '.format(i))
        f.write('"}}{0}" free_text_fmt, \\\n'.format(log_message_delimiter))

        f.write('        v1, ')
        for j in range(2, i+1):
            f.write('v{0}, '.format(j))
        f.write('## __VA_ARGS__)\n')

f.write('\n')
f.write('#if 0\n')
f.write('# This file was generated by this Python script:\n')
f.write('#\n')
this_file_contents = open(sys.argv[0]).read()
f.write(this_file_contents)
f.write('#endif // 0\n')
#endif // 0
