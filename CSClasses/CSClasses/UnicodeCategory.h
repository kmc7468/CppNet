#ifndef SYSTEM_GLOBALIZATION_UNICODECATEGORY_H
#define SYSTEM_GLOBALIZATION_UNICODECATEGORY_H

namespace System
{
	namespace Globalization
	{
		// UNICODE 9.0
		// http://www.unicode.org/reports/tr44/
		// 5.7.1 General Category Values
		// Tabel 12. General_Category Values

		enum class UnicodeCategory
		{
			UppercaseLetter,
			LowercaseLetter,
			TitlecaseLetter,
			ModifierLetter,
			OtherLetter,
			NonspacingMark,
			SpacingMark,
			EnclosingMark,
			DecimalNumber,
			LetterNumber,
			OtherNumber,
			ConnectorPunctuation,
			DashPunctuation,
			OpenPunctuation,
			ClosePunctuation,
			InitialPunctuation,
			FinalPunctuation,
			OtherPunctuation,
			MathSymbol,
			CurrencySymbol,
			ModifierSymbol,
			OtherSymbol,
			SpaceSeparator,
			LineSeparator,
			ParagraphSeparator,
			Control,
			Format,
			Surrogate,
			PrivateUse,
			Unassigned,
		};
	}
}

#endif