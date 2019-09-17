#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace config {
  static const int TILE_PAD = 4;
  static const int TILE_SIZE = 512;
  static const int VERTEX_BUFFER_SIZE = 3;
  static const int VERTICES_PER_TILE = 6;
  static const int WORLD_WIDTH_PX = 20;
  static const int WORLD_HEIGHT_PX = 20;
  static const int PYRAMID_MAX_LEVEL = 15;
  static const int TEXTURE_ARRAY_SIZE = 8;
  static const int TILE_COUNT = 128; // 8 * 4 * 4
  static const int MAX_TEXTURE_COUNT = 128; // 8 * 4 * 4
  enum TEXTURE_TYPE { RGB, NORMAL, MEAN_CURVATURE, MULTI_SCALE_MEAN_CURVATURE, PINHOLES };
}

#endif
