#ifndef SYSTEM_GLOBALIZATION_UNICODECATEGORY_H
#define SYSTEM_GLOBALIZATION_UNICODECATEGORY_H

namespace System
{
	namespace Globalization
	{
		enum class UnicodeCategory
		{
			UppercaseLetter,
			LowercaseLetter,
			TitlecaseLetter,
			ModifierLetter,
			OtherLetter,
			NonSpacingMark,
			SpacingCombiningMark,
			EnclosingMark,
			DecimalDigitNumber,
			LetterNumber,
			OtherNumber,
			SpaceSeparator,
			LineSeparator,
			ParagraphSeparator,
			Control,
			Format,
			Surrogate,
			PrivateUse,
			ConnectorPunctuation,
			DashPunctuation,
			OpenPunctuation,
			ClosePunctuation,
			InitialQuotePunctuation,
			FinalQuotePunctuation,
			OtherPunctuation,
			MathSymbol,
			CurrencySymbol,
			ModifierSymbol,
			OtherSymbol,
			OtherNotAssigned
		};
	}
}

#endif