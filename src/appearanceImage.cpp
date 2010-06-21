/*
 * AppearanceAbstract.cpp
 *
 *  Created on: 14 avr. 2010
 *      Author: jeanmarie
 */

#include "rtslam/appearanceImage.hpp"
#include "image/Image.hpp"

namespace jafar {
	namespace rtslam {
		using namespace std;

		AppearanceImagePoint::AppearanceImagePoint(const image::Image& patch) : patch(patch) {
			computePatchIntegrals();
		}

		AppearanceImagePoint::~AppearanceImagePoint() {
		}

		AppearanceAbstract* AppearanceImagePoint::clone()
		{
			AppearanceImagePoint* app = new AppearanceImagePoint(patch.width(), patch.height(), patch.depth());
			patch.copy(app->patch,0,0,0,0);
			app->patchSum = patchSum;
			app->patchSquareSum = patchSquareSum;
			return app;
		}

		void AppearanceImagePoint::computePatchIntegrals(){
			patchSum = 0;
			patchSquareSum = 0;
			uchar* pix = patch.data();
			for (int u = 0; u < patch.width()*patch.height(); u++){
				patchSum += *pix;
				patchSquareSum += (*pix) * (*pix);
				pix ++;
			}
		}

	}
}
