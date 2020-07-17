/* File automatically created by
 * tensorflow/examples/speech_commands/wav_to_features.py \
 * --sample_rate=16000 \
 * --clip_duration_ms=1000 \
 * --window_size_ms=30 \
 * --window_stride_ms=20 \
 * --feature_bin_count=40 \
 * --quantize=1 \
 * --preprocess="micro" \
 * --input_wav="/content/data_yn/audio_no__1.wav" \
 * --output_c_file="/content/yn_no_features_data.cc" \
 */

#include "yn_no_features_data.h"

const int g_audio_no__1_width = 40;
const int g_audio_no__1_height = 49;
const unsigned char g_audio_no__1_data[] = {
  228, 208, 211, 197, 182, 171, 169, 175, 187, 179, 
  196, 179, 183, 187, 190, 184, 190, 180, 192, 175, 
  190, 189, 192, 192, 200, 188, 201, 193, 201, 188, 
  198, 182, 194, 196, 202, 194, 200, 190, 201, 200, 
  198, 192, 207, 188, 198, 187, 194, 183, 193, 171, 
  130, 154, 178, 175, 181, 169, 180, 170, 173, 179, 
  186, 171, 187, 180, 185, 174, 198, 189, 191, 177, 
  185, 185, 197, 182, 201, 187, 196, 191, 198, 185, 
  209, 201, 201, 163, 178, 95, 172, 182, 164, 151, 
  184, 171, 171, 147, 170, 161, 186, 170, 178, 179, 
  190, 164, 191, 174, 192, 185, 190, 167, 188, 184, 
  192, 184, 202, 185, 186, 163, 190, 177, 194, 179, 
  191, 155, 192, 184, 191, 164, 172, 152, 187, 159, 
  173, 178, 184, 138, 157, 160, 162, 168, 188, 167, 
  154, 162, 179, 159, 184, 164, 177, 162, 191, 179, 
  185, 165, 170, 162, 188, 180, 195, 168, 190, 169, 
  197, 175, 195, 170, 178, 177, 187, 117, 166, 147, 
  156, 155, 184, 179, 176, 137, 181, 159, 179, 149, 
  175, 135, 134, 143, 182, 158, 169, 157, 180, 168, 
  174, 171, 177, 150, 172, 164, 184, 167, 197, 169, 
  179, 175, 197, 140, 166, 146, 184, 181, 183, 139, 
  170, 158, 178, 152, 167, 107, 176, 162, 166, 157, 
  184, 164, 173, 125, 175, 162, 166, 127, 188, 162, 
  190, 167, 184, 141, 189, 159, 177, 178, 189, 152, 
  175, 168, 184, 158, 188, 176, 177, 107, 145, 143, 
  164, 136, 197, 154, 162, 162, 191, 147, 169, 161, 
  185, 139, 181, 148, 181, 133, 171, 144, 168, 116, 
  165, 129, 178, 152, 184, 157, 190, 173, 184, 148, 
  207, 174, 210, 183, 204, 187, 203, 149, 185, 169, 
  145, 143, 151, 130, 149, 160, 182, 141, 184, 162, 
  180, 138, 171, 117, 150, 117, 150, 105, 152, 78, 
  163, 161, 179, 146, 184, 144, 181, 141, 163, 156, 
  248, 221, 244, 217, 216, 194, 206, 166, 170, 139, 
  188, 170, 182, 171, 189, 125, 159, 136, 184, 150, 
  166, 102, 144, 144, 185, 99, 165, 141, 170, 136, 
  178, 142, 176, 144, 173, 132, 178, 159, 176, 172, 
  223, 219, 246, 224, 243, 220, 236, 190, 180, 139, 
  184, 182, 207, 189, 203, 179, 197, 197, 213, 171, 
  191, 168, 188, 187, 172, 159, 175, 133, 173, 129, 
  170, 127, 192, 144, 164, 151, 182, 133, 177, 165, 
  236, 220, 239, 215, 241, 221, 240, 212, 201, 198, 
  199, 195, 218, 187, 204, 188, 233, 212, 224, 197, 
  200, 160, 204, 197, 196, 112, 192, 187, 207, 207, 
  221, 178, 202, 174, 185, 169, 188, 128, 183, 185, 
  223, 203, 206, 207, 234, 209, 203, 199, 230, 216, 
  224, 206, 222, 195, 225, 215, 243, 226, 243, 210, 
  220, 193, 219, 206, 213, 152, 190, 141, 213, 202, 
  234, 213, 228, 199, 193, 196, 209, 157, 203, 166, 
  216, 195, 203, 192, 207, 174, 211, 207, 232, 217, 
  238, 204, 219, 199, 219, 218, 235, 194, 221, 193, 
  218, 184, 200, 182, 203, 153, 187, 180, 214, 189, 
  215, 195, 227, 193, 202, 191, 214, 173, 197, 175, 
  205, 176, 194, 185, 220, 192, 207, 200, 226, 202, 
  231, 210, 228, 202, 223, 209, 214, 154, 208, 182, 
  199, 182, 207, 176, 208, 151, 176, 198, 217, 185, 
  212, 185, 202, 185, 208, 171, 201, 184, 210, 166, 
  201, 158, 189, 169, 214, 184, 184, 165, 225, 192, 
  205, 201, 220, 193, 231, 193, 202, 146, 180, 175, 
  185, 128, 200, 159, 175, 145, 165, 184, 213, 173, 
  209, 166, 190, 188, 213, 149, 182, 167, 201, 159, 
  188, 138, 175, 148, 210, 164, 193, 174, 229, 203, 
  225, 169, 204, 187, 211, 159, 174, 0, 155, 156, 
  185, 166, 207, 169, 174, 90, 148, 159, 167, 110, 
  184, 153, 183, 162, 200, 99, 157, 152, 190, 154, 
  179, 0, 168, 117, 206, 161, 178, 182, 220, 181, 
  198, 154, 193, 174, 209, 156, 153, 85, 180, 102, 
  167, 135, 193, 138, 140, 116, 151, 148, 159, 116, 
  166, 78, 175, 163, 190, 0, 130, 120, 175, 0, 
  176, 0, 174, 95, 195, 150, 198, 164, 195, 181, 
  213, 175, 188, 155, 198, 160, 190, 78, 154, 68, 
  183, 135, 174, 119, 177, 157, 150, 153, 167, 0, 
  150, 51, 191, 192, 213, 0, 132, 162, 189, 112, 
  168, 0, 156, 129, 190, 123, 197, 110, 163, 163, 
  186, 0, 172, 95, 157, 154, 181, 0, 116, 149, 
  190, 155, 147, 119, 172, 126, 164, 0, 120, 0, 
  178, 146, 194, 174, 190, 0, 112, 112, 167, 119, 
  123, 0, 175, 143, 189, 164, 199, 122, 164, 68, 
  151, 0, 0, 0, 157, 85, 157, 0, 170, 138, 
  185, 155, 184, 172, 170, 112, 181, 0, 0, 0, 
  170, 137, 151, 85, 169, 0, 114, 179, 200, 107, 
  0, 0, 112, 107, 175, 160, 188, 95, 112, 0, 
  122, 0, 68, 0, 0, 0, 146, 159, 189, 158, 
  182, 135, 193, 135, 102, 150, 194, 0, 0, 0, 
  168, 139, 99, 0, 102, 0, 140, 85, 132, 0, 
  0, 0, 51, 0, 171, 112, 138, 0, 68, 0, 
  0, 0, 0, 0, 0, 0, 105, 159, 181, 114, 
  163, 114, 179, 51, 51, 51, 184, 0, 0, 0, 
  157, 135, 0, 0, 0, 0, 68, 0, 102, 0, 
  0, 78, 164, 0, 163, 85, 165, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 90, 0, 179, 150, 
  168, 171, 157, 0, 0, 0, 145, 0, 0, 0, 
  95, 0, 0, 0, 0, 0, 85, 0, 0, 0, 
  85, 141, 186, 158, 157, 0, 132, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 133, 85, 
  190, 184, 143, 0, 0, 0, 102, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  159, 157, 175, 123, 171, 68, 164, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 90, 107, 
  181, 119, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  142, 95, 105, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  138, 0, 51, 0, 0, 0, 134, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 51, 0, 68, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 128, 99, 107, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 68, 0, 0, 125, 152, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 68, 51, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 78, 0, 0, 0, 
  0, 0, 0, 0, 0, 51, 143, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 132, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 78, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 51, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 95, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 85, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 95, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 68, 78, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
};