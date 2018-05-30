#pragma once
#include "SkFloatPointArray.h"

namespace skylina {
namespace app {

class SkFSurfaceMesh
{
public:
	SkFSurfaceMesh() = default;
	SkFSurfaceMesh(const SkFloatPointArray& points,
		const std::vector<unsigned>& vertsConnect,
		const std::vector<unsigned>& vertsCount) throw(std::invalid_argument);
	SkFSurfaceMesh(SkFloatPointArray&& points,
		std::vector<unsigned>&& vertsConnect,
		std::vector<unsigned>&& vertsCount) throw(std::invalid_argument);
	const SkFloatPointArray& points() const {
		return m_meshPoints;
	}
	void face(unsigned faceID, std::vector<unsigned>& vertices);
	void edge(unsigned EdgeID, unsigned& vtxst, unsigned& vtxnd);

private:
	void cacheFaceCount();
	void mapEdgeVertsIndices();
	bool hasEdge(unsigned st, unsigned nd);
private:
	SkFloatPointArray m_meshPoints;
	std::vector<unsigned> m_faceVertsIndices;
	std::vector<unsigned> m_faceVertsCount;
	std::vector<unsigned> m_faceCountCache;
	std::vector<unsigned> m_edgeVertsIndices;
};

}//namespace app
}//namespace skylina