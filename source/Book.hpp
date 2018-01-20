///
/// Book.hpp
/// Manages the eBook.
///

#ifndef EBOOK_BOOK_HPP_
#define EBOOK_BOOK_HPP_

#include <vector>
#include <string>
#include <unordered_map>

#include "zipper/unzipper.h"

using namespace zipper;

class Book
{
public:
	///
	/// Init book.
	///
	Book(const std::string& epub);

	///
	/// Cleanup
	///
 	~Book();

	///
	/// Parse the ebook container.
	///
	void parseContainer(Unzipper& zip);

	///
	/// Parse the ebook opf.
	///
	void parseOPF(Unzipper& zip);

	///
	/// Parse the ebook pages.
	///
	void parsePages(Unzipper& zip);

	///
	/// Get current book name.
	///
	std::string getBook() const;
	
private:
	///
	/// Open an ebook to read.
	///	
	void openBook(const std::string& epub);

private:
	std::string m_title;
	std::string m_author;
	std::string m_opf;
	std::string m_book;
	std::string m_container;

	// id, href
	std::unordered_map<std::string, std::string> m_manifest;

	// order of book, THIS IS ORDERED DONT MESS WITH ORDER
	std::vector<std::string> m_spine;

	// All the text in the book.
	std::vector<std::string> m_text;
};

#endif