#include "SkSurfaceMesh.h"
#include <numeric>

namespace skylina {
namespace app {

SkFSurfaceMesh::SkFSurfaceMesh(const SkFloatPointArray& points,
	const std::vector<unsigned>& vertsConnect,
	const std::vector<unsigned>& vertsCount)
	:m_meshPoints(points),
	m_faceVertsIndices(vertsConnect),
	m_faceVertsCount(vertsCount)
{
	if ((unsigned)m_faceVertsIndices.size()
		!= std::accumulate(m_faceVertsCount.begin(), m_faceVertsCount.end(), 0)) {
		throw std::invalid_argument("wrong face-vertices number!");
	}
	cacheFaceCount();
	mapEdgeVertsIndices();
}

SkFSurfaceMesh::SkFSurfaceMesh(SkFloatPointArray&& points,
	std::vector<unsigned>&& vertsConnect,
	std::vector<unsigned>&& vertsCount)
	: m_meshPoints(std::move(points)),
	m_faceVertsIndices(std::move(vertsConnect)),
	m_faceVertsCount(std::move(vertsCount))
{
	if ((unsigned)m_faceVertsIndices.size()
		!= std::accumulate(m_faceVertsCount.begin(), m_faceVertsCount.end(), 0)) {
		throw std::invalid_argument("wrong face-vertices number!");
	}
	cacheFaceCount();
	mapEdgeVertsIndices();
}

void SkFSurfaceMesh::face(unsigned faceID, std::vector<unsigned>& vertices)
{
	vertices.resize(m_faceVertsCount[faceID]);
	for (unsigned i = m_faceCountCache[faceID],p=0; i != (unsigned)vertices.size(); ++i,++p) {
		vertices[p] = m_faceVertsIndices[i];
	}
}

void SkFSurfaceMesh::cacheFaceCount()
{
	m_faceCountCache.resize(m_faceVertsCount.size());
	unsigned countSum{ 0 };
	for (size_t i = 0; i != m_faceCountCache.size(); ++i) {
		m_faceCountCache[i] = countSum;
		countSum += m_faceVertsCount[i];
	}
}

void SkFSurfaceMesh::mapEdgeVertsIndices()
{
	m_edgeVertsIndices.clear();
	for (unsigned i = 0; i != (unsigned)m_faceVertsCount.size(); ++i) {
		unsigned count = m_faceVertsCount[i];
		unsigned countBase = m_faceCountCache[i];
		for (unsigned p = countBase; p != countBase + count; ++p) {
			unsigned st = m_faceVertsIndices[countBase + p];
			unsigned nd = m_faceVertsIndices[countBase + (p + 1) % count];
			if (st > nd) {
				unsigned swap = nd;
				nd = st;
				st = swap;
			}
			if (!hasEdge(st, nd)) {
				m_edgeVertsIndices.push_back(st);
				m_edgeVertsIndices.push_back(nd);
			}
		}
	}
}

bool SkFSurfaceMesh::hasEdge(unsigned st, unsigned nd)
{
	for (unsigned t = 0; t != (unsigned)(m_edgeVertsIndices.size() / 2); ++t) {
		if (m_edgeVertsIndices[2 * t] == st && m_edgeVertsIndices[2 * t + 1] == nd)
			return true;
	}
	return false;
}

}//namespace app
}//namespace skylina