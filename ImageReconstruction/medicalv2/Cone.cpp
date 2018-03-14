#include "Cone.h"

Cone::Cone(double startX ,double startY ,double startZ, double xImagePlane, double yImagePlane, double halfAngle)
{
	SetStartX(startX);
    SetStartY(startY);
	SetStartZ(startZ);
	SetXImagePlane(xImagePlane);
    SetYImagePlane(yImagePlane);
	SetHalfAngle(halfAngle);
}
