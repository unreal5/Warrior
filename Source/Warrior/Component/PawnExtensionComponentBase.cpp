#include "PawnExtensionComponentBase.h"

APawn* UPawnExtensionComponentBase::GetOwningPawn() const
{
	return GetOwningPawn<APawn>();
}
