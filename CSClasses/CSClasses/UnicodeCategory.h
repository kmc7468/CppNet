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
			CasedLetter,
			ModifierLetter,
			OtherLetter,
			Letter,
			NonspacingMark,
			SpacingMark,
			EnclosingMark,
			Mark,
			DecimalNumber,
			LetterNumber,
			OtherNumber,
			Number,
			ConnectorPunctuation,
			DashPunctuation,
			OpenPunctuation,
			ClosePunctuation,
			InitialPunctuation,
			FinalPunctuation,
			OtherPunctuation,
			Punctuation,
			MathSymbol,
			CurrencySymbol,
			ModifierSymbol,
			OtherSymbol,
			Symbol,
			SpaceSeparator,
			LineSeparator,
			ParagraphSeparator,
			Separator,
			Control,
			Format,
			Surrogate,
			PrivateUse,
			Unassigned,
			Other
		};
	}
}

#endif