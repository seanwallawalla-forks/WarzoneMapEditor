#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include "World3d.h"
#include "wmt.hpp"

extern char* texpagesPath;

/* The shift on a world coordinate to get the tile coordinate */
#define TILE_SHIFT 7
static inline int32_t world_coord(int32_t mapCoord) { return (uint32_t)mapCoord << TILE_SHIFT; }
static inline int32_t map_coord(int32_t worldCoord) { return worldCoord >> TILE_SHIFT; }

class Terrain : public Object3d {
public:
	struct tileinfo {
		bool triflip;
		float height;
		int texture;
		int rot;
		bool fx, fy;
		WMT_TerrainTypes tt;
	} tiles[256][256];
	int w, h;
	WZtileset tileset;
	int DatasetLoaded;
	void UpdateTexpageCoords();
	void GetHeightmapFromMWT(WZmap* m);
	void CreateTexturePage(char* basepath, int qual, SDL_Renderer* rend);
	void BufferData(unsigned int shader);
};

#endif /* end of include guard: TERRAIN_H_INCLUDED */
