
/**
 *	Include Math Types
 */
#include <ING\Math\Types\Types.h>



/**
 *	Include AMath Types
 */
#include <ING\AMath\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Constructors
		 */
		CVector3::CVector3(const AMath::CVector3& amathV) {

			memcpy(this, &amathV, 12);

		}



		/**
		 *	Methods
		 */
		Vector3 CVector3::Transpose() const {
			return Vector3(
				x, y, z
			);
		}

		float	CVector3::Length() const {

			return sqrt(x * x + y * y + z * z);

		}



		/**
		 *	Operators
		 */
		Matrix3x4 CVector3::operator*(const Vector4& next) {
			return Matrix3x4(
				next * x,
				next * y,
				next * z
			);
		}

		Matrix3x3 CVector3::operator*(const Vector3& next) {
			return Matrix3x3(
				next * x,
				next * y,
				next * z
			);
		}

		Matrix3x2 CVector3::operator*(const Vector2& next) {
			return Matrix3x2(
				next * x,
				next * y,
				next * z
			);
		}

		void  CVector3::operator=(const AMath::CVector3& amathV) {

			memcpy(this, &amathV, 12);

		}

	}

}