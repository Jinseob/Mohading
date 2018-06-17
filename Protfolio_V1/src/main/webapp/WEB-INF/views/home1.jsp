<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%-- <%@ page session="false" %> --%>

<html>
<head>
	<title>Home</title>
	<link rel="stylesheet" type="text/css" href="resources/css/style.css">
	<jsp:directive.include file="/WEB-INF/views/common/taglib.jsp" />
</head>
<body>
<h1>
	Hello world!
</h1>
<br/>
<h1>
	Portfolio 만들어봐욤!
</h1>
<P>  The time on the server is ${serverTime}. </P>

<table>
	<caption>전체 집계</caption>
	<colgroup>
		<col style="width: 100px;" />
		<col style="width: 100px;" />
		<col style="width: 100px;" />
		<col style="width: 100px;" />
		<col style="width: 100px;" />
	</colgroup>
	<thead>
		<tr>
			<th scope="col">ID</th>
			<th scope="col">제목</th>
			<th scope="col">내용</th>
			<th scope="col">작성자</th>
			<th scope="col">작성일</th>
		</tr>
	</thead>
	<tbody>
		<c:choose>
			<c:when test="${fn:length(list) > 0 }">
				<c:forEach items="${list }" var="list" varStatus="status">
					<tr>
						<td>${list.id}</td>
						<td>${list.title}</td>
						<td>${list.content}</td>
						<td>${list.cre_id}</td>
						<td>${list.cre_dt}</td>
					</tr>
				</c:forEach>
			</c:when>
			<c:otherwise>
				<tr>
					<td colspan="5">검색된 자료가 없습니다</td>
				</tr>
			</c:otherwise>
		</c:choose>
	</tbody>
</table>

</body>
</html>
